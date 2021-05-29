
#ifndef GLUE_HPP
#define GLUE_HPP

#ifdef _WIN32
#pragma warning( push )
#pragma warning( disable : 4251 )
#pragma warning( disable : 4275 )
#endif
#include <node.h>
#ifdef _WIN32
#pragma warning( pop )
#endif

namespace SBGCK
{
  using v8::FunctionCallbackInfo;
  using v8::Value;

  class Glue
  {
  public:
    static void Method_Init(const FunctionCallbackInfo<Value> &args);
    static void Method_LoadGame(const FunctionCallbackInfo<Value> &args);
    static void Method_SetBoard(const FunctionCallbackInfo<Value> &args);
    static void Method_PlaySample(const FunctionCallbackInfo<Value> &args);
    static void Method_PlaySampleSync(const FunctionCallbackInfo<Value> &args);
    static void Method_StopAllAudio(const FunctionCallbackInfo<Value> &args);
    static void Method_CalibrateReferenceFrame(const FunctionCallbackInfo<Value> &args);
    static void Method_DetectColorCalibrationCard(const FunctionCallbackInfo<Value> &args);
    static void Method_QueryTokens(const FunctionCallbackInfo<Value> &args);
  };

} // namespace SBGCK

#endif // GLUE_HPP
