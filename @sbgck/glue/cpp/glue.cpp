#include <sbgck_core/sbgck.hpp>
#include "glue.hpp"

using namespace SBGCK;

// using v8::Exception;
using v8::Boolean;
using v8::FunctionCallbackInfo;
using v8::Isolate;
using v8::JSON;
using v8::Local;
using v8::Number;
using v8::Object;
// using v8::String;
using v8::Value;

Engine engine;

//  bool init(string applicationDir, string cameraUrl);
void Glue::Method_Init(const FunctionCallbackInfo<Value> &args)
{
    Isolate *isolate = args.GetIsolate();

    // Check the number of arguments passed.
    if (args.Length() < 2)
    {
        // Throw an Error that is passed back to JavaScript
        isolate->ThrowException(v8::Exception::TypeError(
            v8::String::NewFromUtf8(isolate, "Wrong number of arguments").ToLocalChecked()));
        return;
    }

    // Check the argument types
    if (!args[0]->IsString() && !args[0]->IsObject())
    {
        isolate->ThrowException(v8::Exception::TypeError(
            v8::String::NewFromUtf8(isolate, "Wrong arguments").ToLocalChecked()));
        return;
    }

    v8::String::Utf8Value applicationDir(isolate, args[0]);

    // Check the argument types
    if (!args[1]->IsString() && !args[1]->IsObject())
    {
        isolate->ThrowException(v8::Exception::TypeError(
            v8::String::NewFromUtf8(isolate, "Wrong arguments").ToLocalChecked()));
        return;
    }

    v8::String::Utf8Value cameraUrl(isolate, args[1]);

    Log(typelog::INFO) << "SBGCK init (" << (*applicationDir) << ", " << (*cameraUrl) << ")";

    bool result = engine.init((*applicationDir), (*cameraUrl));

    Local<Boolean> resultValue = Boolean::New(isolate, result);
    args.GetReturnValue().Set(resultValue);
}

// bool loadGame(string gameName, string lang);
void Glue::Method_LoadGame(const FunctionCallbackInfo<Value> &args)
{
    Isolate *isolate = args.GetIsolate();

    // Check the number of arguments passed.
    if (args.Length() < 2)
    {
        // Throw an Error that is passed back to JavaScript
        isolate->ThrowException(v8::Exception::TypeError(
            v8::String::NewFromUtf8(isolate, "Wrong number of arguments").ToLocalChecked()));
        return;
    }

    // Check the argument types
    if (!args[0]->IsString() && !args[0]->IsObject())
    {
        isolate->ThrowException(v8::Exception::TypeError(
            v8::String::NewFromUtf8(isolate, "Wrong arguments").ToLocalChecked()));
        return;
    }

    v8::String::Utf8Value gameName(isolate, args[0]);

    // Check the argument types
    if (!args[1]->IsString() && !args[1]->IsObject())
    {
        isolate->ThrowException(v8::Exception::TypeError(
            v8::String::NewFromUtf8(isolate, "Wrong arguments").ToLocalChecked()));
        return;
    }

    v8::String::Utf8Value lang(isolate, args[1]);

    Log(typelog::INFO) << "SBGCK loadGame (" << (*gameName) << ", " << (*lang) << ")";

    bool result = engine.loadGame((*gameName), (*lang));

    Local<Boolean> resultValue = Boolean::New(isolate, result);
    args.GetReturnValue().Set(resultValue);
}

// bool loadBoard(string boardName);
void Glue::Method_LoadBoard(const FunctionCallbackInfo<Value> &args)
{

    Isolate *isolate = args.GetIsolate();

    // Check the number of arguments passed.
    if (args.Length() < 1)
    {
        // Throw an Error that is passed back to JavaScript
        isolate->ThrowException(v8::Exception::TypeError(
            v8::String::NewFromUtf8(isolate, "Wrong number of arguments").ToLocalChecked()));
        return;
    }

    // Check the argument types
    if (!args[0]->IsString() && !args[0]->IsObject())
    {
        isolate->ThrowException(v8::Exception::TypeError(
            v8::String::NewFromUtf8(isolate, "Wrong arguments").ToLocalChecked()));
        return;
    }

    v8::String::Utf8Value boardName(isolate, args[0]);

    Log(typelog::INFO) << "SBGCK loadBoard (" << (*boardName) << ")";

    bool result = engine.loadBoard((*boardName));

    Local<Boolean> resultValue = Boolean::New(isolate, result);
    args.GetReturnValue().Set(resultValue);
}

// bool playSample(string sampleName);
void Glue::Method_PlaySample(const FunctionCallbackInfo<Value> &args)
{

    Isolate *isolate = args.GetIsolate();

    // Check the number of arguments passed.
    if (args.Length() < 1)
    {
        // Throw an Error that is passed back to JavaScript
        isolate->ThrowException(v8::Exception::TypeError(
            v8::String::NewFromUtf8(isolate, "Wrong number of arguments").ToLocalChecked()));
        return;
    }

    // Check the argument types
    if (!args[0]->IsString() && !args[0]->IsObject())
    {
        isolate->ThrowException(v8::Exception::TypeError(
            v8::String::NewFromUtf8(isolate, "Wrong arguments").ToLocalChecked()));
        return;
    }

    v8::String::Utf8Value sampleName(isolate, args[0]);

    Log(typelog::INFO) << "SBGCK playSample (" << (*sampleName) << ")";

    bool result = engine.playSample((*sampleName));

    Local<Boolean> resultValue = Boolean::New(isolate, result);
    args.GetReturnValue().Set(resultValue);
}

// bool playSampleSync(string sampleName, bool isLocalized);
void Glue::Method_PlaySampleSync(const FunctionCallbackInfo<Value> &args)
{
    Isolate *isolate = args.GetIsolate();

    // Check the number of arguments passed.
    if (args.Length() < 2)
    {
        // Throw an Error that is passed back to JavaScript
        isolate->ThrowException(v8::Exception::TypeError(
            v8::String::NewFromUtf8(isolate, "Wrong number of arguments").ToLocalChecked()));
        return;
    }

    // Check the argument types
    if (!args[0]->IsString() && !args[0]->IsObject())
    {
        isolate->ThrowException(v8::Exception::TypeError(
            v8::String::NewFromUtf8(isolate, "Wrong arguments").ToLocalChecked()));
        return;
    }

    v8::String::Utf8Value sampleName(isolate, args[0]);

    // Check the argument types
    if (!args[1]->IsBoolean() && !args[1]->IsObject())
    {
        isolate->ThrowException(v8::Exception::TypeError(
            v8::String::NewFromUtf8(isolate, "Wrong arguments").ToLocalChecked()));
        return;
    }

    bool isLocalized = args[1].As<Boolean>()->Value();

    Log(typelog::INFO) << "SBGCK playSampleSync (" << (*sampleName) << ", " << isLocalized << ")";

    bool result = engine.playSampleSync((*sampleName), isLocalized);

    Local<Boolean> resultValue = Boolean::New(isolate, result);
    args.GetReturnValue().Set(resultValue);
}

// void stopAllAudio();
void Glue::Method_StopAllAudio(const FunctionCallbackInfo<Value> &args)
{
    Isolate *isolate = args.GetIsolate();

    // Check the number of arguments passed.
    if (args.Length() != 0)
    {
        // Throw an Error that is passed back to JavaScript
        isolate->ThrowException(v8::Exception::TypeError(
            v8::String::NewFromUtf8(isolate, "Wrong number of arguments").ToLocalChecked()));
        return;
    }

    Log(typelog::INFO) << "SBGCK stopAllAudio ()";

    bool result = engine.stopAllAudio();

    Local<Boolean> resultValue = Boolean::New(isolate, result);
    args.GetReturnValue().Set(resultValue);
}

// bool calibrateReferenceFrame();
void Glue::Method_CalibrateReferenceFrame(const FunctionCallbackInfo<Value> &args)
{
    Isolate *isolate = args.GetIsolate();

    // Check the number of arguments passed.
    if (args.Length() != 0)
    {
        // Throw an Error that is passed back to JavaScript
        isolate->ThrowException(v8::Exception::TypeError(
            v8::String::NewFromUtf8(isolate, "Wrong number of arguments").ToLocalChecked()));
        return;
    }

    Log(typelog::INFO) << "SBGCK calibrateReferenceFrame ()";

    bool result = engine.calibrateReferenceFrame();

    Local<Boolean> resultValue = Boolean::New(isolate, result);
    args.GetReturnValue().Set(resultValue);
}

// bool detectColorCalibrationCard();
void Glue::Method_DetectColorCalibrationCard(const FunctionCallbackInfo<Value> &args)
{
    Isolate *isolate = args.GetIsolate();

    // Check the number of arguments passed.
    if (args.Length() != 0)
    {
        // Throw an Error that is passed back to JavaScript
        isolate->ThrowException(v8::Exception::TypeError(
            v8::String::NewFromUtf8(isolate, "Wrong number of arguments").ToLocalChecked()));
        return;
    }

    Log(typelog::INFO) << "SBGCK detectColorCalibrationCard ()";

    bool result = engine.detectColorCalibrationCard();

    Local<Boolean> resultValue = Boolean::New(isolate, result);
    args.GetReturnValue().Set(resultValue);
}

// string queryTokens(string json);
void Glue::Method_QueryTokens(const FunctionCallbackInfo<Value> &args)
{
    Isolate *isolate = args.GetIsolate();

    // Check the number of arguments passed.
    if (args.Length() < 1)
    {
        // Throw an Error that is passed back to JavaScript
        isolate->ThrowException(v8::Exception::TypeError(
            v8::String::NewFromUtf8(isolate, "Wrong number of arguments").ToLocalChecked()));
        return;
    }

    // Check the argument types
    if (!args[0]->IsString() && !args[0]->IsObject())
    {
        isolate->ThrowException(v8::Exception::TypeError(
            v8::String::NewFromUtf8(isolate, "Wrong arguments").ToLocalChecked()));
        return;
    }

    v8::String::Utf8Value json(isolate, args[0]);

    Log(typelog::INFO) << "SBGCK queryTokens (" << (*json) << ")";

    string result = engine.queryTokens((*json));

    args.GetReturnValue().Set(v8::String::NewFromUtf8(isolate, result.c_str()).ToLocalChecked());
}
