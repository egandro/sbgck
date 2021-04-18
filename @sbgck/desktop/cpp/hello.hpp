
#ifndef HELLO_H
#define HELLO_H

#include <node.h>

namespace sbgck
{
  using v8::FunctionCallbackInfo;
  using v8::Value;

  class Hello
  {
  public:
    static void MethodHello(const FunctionCallbackInfo<Value> &args);
  };

} // namespace sbgck

#endif // HELLO_H
