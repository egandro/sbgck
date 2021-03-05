#include <node.h>

#include "log.hpp"
#include "hello.hpp"

structlog LOGCFG = {};

namespace sbgck
{
  using v8::Local;
  using v8::Object
  ;
  void Initialize(Local<Object> exports)
  {
    if (getenv("DEBUG"))
    {
      LOGCFG.prefix = (char *)NODE_MODULE_NAME;
      LOGCFG.headers = true;
      LOGCFG.level = DEBUG;

      Log(INFO) << "Initialize()";
    }
    NODE_SET_METHOD(exports, "hello", Hello::MethodHello);
  }

  NODE_MODULE(NODE_GYP_MODULE_NAME, Initialize)

} // namespace sbgck
