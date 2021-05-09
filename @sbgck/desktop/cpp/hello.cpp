#include <node.h>

#include <sbgck_opencv/log.hpp>
#include <sbgck_opencv/version.hpp>
#include <soloud/soloud.h>

#define ASSETSYS_IMPLEMENTATION
#include "libs/assetsys.h"
#define STRPOOL_IMPLEMENTATION
#include <libs/strpool.h>

#include "hello.hpp"

namespace sbgck
{
  using v8::Exception;
  using v8::FunctionCallbackInfo;
  using v8::Isolate;
  using v8::JSON;
  using v8::Local;
  using v8::Number;
  using v8::Object;
  using v8::String;
  using v8::Value;

  void Hello::MethodHello(const FunctionCallbackInfo<Value> &args)
  {
    Isolate *isolate = args.GetIsolate();
    args.GetReturnValue().Set(String::NewFromUtf8(isolate, "world").ToLocalChecked());
  }

  void Hello::MethodGetOpenCVVersion(const FunctionCallbackInfo<Value> &args)
  {
    Isolate *isolate = args.GetIsolate();
    args.GetReturnValue().Set(String::NewFromUtf8(isolate, getOpenCVVersion()).ToLocalChecked());
  }

  void Hello::MethodGetSoloudVersion(const FunctionCallbackInfo<Value> &args)
  {
    Isolate *isolate = args.GetIsolate();
    SoLoud::Soloud soLoud;

    int version = soLoud.getVersion();

    args.GetReturnValue().Set(v8::Number::New(isolate, version));
  }

  void Hello::MethodVFSTest(const FunctionCallbackInfo<Value> &args)
  {
    Isolate *isolate = args.GetIsolate();

    // Check the argument types
    if (!args[0]->IsString())
    {
      isolate->ThrowException(Exception::TypeError(
          String::NewFromUtf8(isolate, "Wrong arguments").ToLocalChecked()));
      return;
    }

    String::Utf8Value str(isolate, args[0]);

    if (str.length() == 0)
    {
      isolate->ThrowException(Exception::TypeError(
          String::NewFromUtf8(isolate, "Wrong arguments").ToLocalChecked()));
      return;
    }

    Log(INFO) << "MethodVFSTest directory: '" << *str << "'";

    std::string result = "Data from VFS:\n";

    // from https://github.com/mattiasgustavsson/libs/blob/main/docs/assetsys.md
    const char *path = "/data";

    assetsys_t *assetsys = assetsys_create(0);
    assetsys_error_t status = assetsys_mount(assetsys, *str, path);
    Log(INFO) << "MethodVFSTest status: " << status;

    if( status == ASSETSYS_SUCCESS) {
      Log(INFO) << "MethodVFSTest mounted";
      // Print file names
      int count = assetsys_file_count(assetsys, path);
      Log(INFO) << "MethodVFSTest count: " << count;
      for (int i = 0; i < count; ++i)
      {
          char const *file_name = assetsys_file_name(assetsys, path, i);
          Log(INFO) << "MethodVFSTest file found: " << file_name;
          if(file_name != NULL) {
            result += "    ";
            result += file_name;
            result += "\n";
          }
      }
    }
    Log(INFO) << "MethodVFSTest unmounted";
    assetsys_destroy(assetsys);

    args.GetReturnValue().Set(String::NewFromUtf8(isolate, result.c_str()).ToLocalChecked());
  }

} // namespace sbgck