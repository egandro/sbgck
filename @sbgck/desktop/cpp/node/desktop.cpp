// hello.cc using Node-API
#include <string>
#include <sstream>
#include <iostream>
#include <node.h>
#include <nlohmann/json.hpp>

#include "displayimage.hpp"
#include "version.hpp"


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

  using json = nlohmann::json;

  void MethodHelloWorld(const FunctionCallbackInfo<Value> &args)
  {
    Isolate *isolate = args.GetIsolate();
    args.GetReturnValue().Set(String::NewFromUtf8(isolate, "world").ToLocalChecked());
    //displayImage("/home/pi/projects/opencv/VideoCaptureTest/frame.png");
  }

  void MethodGetOpenCVVersion(const FunctionCallbackInfo<Value> &args)
  {
    Isolate *isolate = args.GetIsolate();
    args.GetReturnValue().Set(String::NewFromUtf8(isolate, getOpenCVVersion()).ToLocalChecked());
  }

  // This is the implementation of the "add" method
  // Input arguments are passed using the
  // const FunctionCallbackInfo<Value>& args struct
  void MethodAdd(const FunctionCallbackInfo<Value> &args)
  {
    Isolate *isolate = args.GetIsolate();

    // Check the number of arguments passed.
    if (args.Length() < 2)
    {
      // Throw an Error that is passed back to JavaScript
      isolate->ThrowException(Exception::TypeError(
          String::NewFromUtf8(isolate, "Wrong number of arguments").ToLocalChecked()));
      return;
    }

    // Check the argument types
    if (!args[0]->IsNumber() || !args[1]->IsNumber())
    {
      isolate->ThrowException(Exception::TypeError(
          String::NewFromUtf8(isolate, "Wrong arguments").ToLocalChecked()));
      return;
    }

    // Perform the operation
    double value =
        args[0].As<Number>()->Value() + args[1].As<Number>()->Value();

    Local<Number> num = Number::New(isolate, value);

    // Set the return value (using the passed in
    // FunctionCallbackInfo<Value>&)

    args.GetReturnValue().Set(num);
  }

  void MethodJson(const FunctionCallbackInfo<Value> &args)
  {
    Isolate *isolate = args.GetIsolate();

    // Check the number of arguments passed.
    if (args.Length() < 1)
    {
      // Throw an Error that is passed back to JavaScript
      isolate->ThrowException(Exception::TypeError(
          String::NewFromUtf8(isolate, "Wrong number of arguments").ToLocalChecked()));
      return;
    }

    // Check the argument types
    if (!args[0]->IsString() && !args[0]->IsObject())
    {
      isolate->ThrowException(Exception::TypeError(
          String::NewFromUtf8(isolate, "Wrong arguments").ToLocalChecked()));
      return;
    }

    // Perform the operation

    json j = json::parse("{}");

    if (args[0]->IsString())
    {
      // https://stackoverflow.com/questions/62370534/how-to-convert-node-v8-string-to-c-string
      String::Utf8Value str(isolate, args[0]);
      j = json::parse(*str);
    }
    else if (args[0]->IsObject())
    {
      // https://github.com/nodejs/node-addon-examples/issues/136
      // https://nodeaddons.com/c-processing-from-node-js-part-2/
      auto json = JSON::Stringify(Isolate::GetCurrent()->GetCurrentContext(), args[0]).ToLocalChecked();
      String::Utf8Value str(isolate, json);
      j = json::parse(*str);
    }

    // Set the return value (using the passed in
    std::string name = "";
    if (j["name"] != nullptr)
    {
      name = j["name"].get<std::string>();
    }

    if (name.empty())
    {
      args.GetReturnValue().Set(Undefined(isolate));
    }
    else
    {
      j.clear();
      j["name"] = name + " changed";

      std::ostringstream oss;
      oss << (void *)name.c_str();
      std::string s(oss.str());

      j["id_from_pointer"] = s;

      Local<String> jsonString = String::NewFromUtf8(isolate,
                                                     j.dump().c_str())
                                     .ToLocalChecked();
      Local<Value> jsonObject = JSON::Parse(Isolate::GetCurrent()->GetCurrentContext(),
                                            Local<String>::Cast(jsonString))
                                    .ToLocalChecked();

      args.GetReturnValue().Set(jsonObject);
    }
  }

  void Initialize(Local<Object> exports)
  {
    NODE_SET_METHOD(exports, "hello", MethodHelloWorld);
    NODE_SET_METHOD(exports, "version", MethodGetOpenCVVersion);
    NODE_SET_METHOD(exports, "add", MethodAdd);
    NODE_SET_METHOD(exports, "json", MethodJson);
  }

  NODE_MODULE(NODE_GYP_MODULE_NAME, Initialize)

} // namespace sbgck
