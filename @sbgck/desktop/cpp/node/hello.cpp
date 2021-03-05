#include <node.h>

#include "hello.hpp"
#include "log.hpp"

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

} // namespace sbgck