#include <node.h>

#include <sbgck_opencv/log.hpp>
#include <sbgck_opencv/version.hpp>
#include <soloud/soloud.h>
#include "hello.hpp"

namespace sbgck
{
  using v8::FunctionCallbackInfo;
  using v8::Isolate;
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

} // namespace sbgck