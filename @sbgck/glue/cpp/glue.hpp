
#ifndef GLUE_HPP
#define GLUE_HPP

#include <node.h>

namespace SBGCK
{
  using v8::FunctionCallbackInfo;
  using v8::Value;

  class Glue
  {
  public:
    static void Method_Init(const FunctionCallbackInfo<Value> &args);
    static void Method_LoadGame(const FunctionCallbackInfo<Value> &args);
    static void Method_LoadBoard(const FunctionCallbackInfo<Value> &args);
    static void Method_PlaySample(const FunctionCallbackInfo<Value> &args);
    static void Method_PlaySampleSync(const FunctionCallbackInfo<Value> &args);
    static void Method_StopAllAudio(const FunctionCallbackInfo<Value> &args);
    static void Method_CalibrateReferenceFrame(const FunctionCallbackInfo<Value> &args);
    static void Method_DetectColorCalibrationCard(const FunctionCallbackInfo<Value> &args);
    static void Method_QueryTokens(const FunctionCallbackInfo<Value> &args);
  };

} // namespace SBGCK

#endif // GLUE_HPP
