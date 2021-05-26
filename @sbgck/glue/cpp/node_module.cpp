#include <node.h>
#define _CRT_SECURE_NO_WARNINGS

#include <sbgck_opencv/log.hpp>
#include "glue.hpp"

structlog LOGCFG = {};

namespace SBGCK
{
  using v8::Local;
  using v8::Object;

  void Initialize(Local<Object> exports)
  {
    if (getenv("GLUEDEBUG"))
    {
      LOGCFG.prefix = (char *)NODE_MODULE_NAME;
      LOGCFG.headers = true;
      LOGCFG.level = typelog::DEBUG;

      Log(typelog::INFO) << "Initialize()";
    }
    NODE_SET_METHOD(exports, "init", Glue::Method_Init);
    NODE_SET_METHOD(exports, "loadGame", Glue::Method_LoadGame);
    NODE_SET_METHOD(exports, "loadBoard", Glue::Method_LoadBoard);
    NODE_SET_METHOD(exports, "playSample", Glue::Method_PlaySample);
    NODE_SET_METHOD(exports, "playSampleSync", Glue::Method_PlaySampleSync);
    NODE_SET_METHOD(exports, "stopAllAudio", Glue::Method_StopAllAudio);
    NODE_SET_METHOD(exports, "calibrateReferenceFrame", Glue::Method_CalibrateReferenceFrame);
    NODE_SET_METHOD(exports, "detectColorCalibrationCard", Glue::Method_DetectColorCalibrationCard);
    NODE_SET_METHOD(exports, "queryTokens", Glue::Method_QueryTokens);
  }

  NODE_MODULE(NODE_GYP_MODULE_NAME, Initialize)

} // namespace SBGCK
