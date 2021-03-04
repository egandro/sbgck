// hello.cc using Node-API
#include <node_api.h>

#include "displayimage.hpp"
#include "version.hpp"

namespace sbgck
{

  napi_value MethodHelloWorld(napi_env env, napi_callback_info args)
  {
    napi_value greeting;
    napi_status status;

    status = napi_create_string_utf8(env, "world", NAPI_AUTO_LENGTH, &greeting);
    if (status != napi_ok)
      return nullptr;
    return greeting;
  }


  napi_value MethodGetOpenCVVersion(napi_env env, napi_callback_info args)
  {
    napi_value greeting;
    napi_status status;

    status = napi_create_string_utf8(env, getOpenCVVersion(), NAPI_AUTO_LENGTH, &greeting);
    if (status != napi_ok)
      return nullptr;
    return greeting;
  }

  napi_value init(napi_env env, napi_value exports)
  {
    napi_status status;
    napi_value fn;

    status = napi_create_function(env, nullptr, 0, MethodHelloWorld, nullptr, &fn);
    if (status != napi_ok)
      return nullptr;

    status = napi_create_function(env, nullptr, 0, MethodGetOpenCVVersion, nullptr, &fn);
    if (status != napi_ok)
      return nullptr;

    status = napi_set_named_property(env, exports, "hello", fn);
    if (status != napi_ok)
      return nullptr;
    return exports;
  }

  NAPI_MODULE(NODE_GYP_MODULE_NAME, init)

} // namespace demo
