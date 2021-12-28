#include <node.h>
#include "../cityhash.h"

namespace cityhash {

using v8::FunctionCallbackInfo;
using v8::Isolate;
using v8::Local;
using v8::Object;
using v8::String;
using v8::Value;

const char* ToCString(const String::Utf8Value& value) {
  return *value ? *value : "<string conversion failed>";
}

void hash64(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();
  v8::String::Utf8Value str(isolate, args[0]);
  const char* cstr = ToCString(str);
  char* result = CityHash64((char*)cstr);
  args.GetReturnValue().Set(String::NewFromUtf8(isolate, result).ToLocalChecked());
}

void hash128(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();
  v8::String::Utf8Value str(isolate, args[0]);
  const char* cstr = ToCString(str);
  char* result = CityHash128((char*)cstr);
  args.GetReturnValue().Set(String::NewFromUtf8(isolate, result).ToLocalChecked());
}


void init(Local<Object> exports) {
  NODE_SET_METHOD(exports, "cityhash64", hash64);
  NODE_SET_METHOD(exports, "cityhash128", hash128);
}

NODE_MODULE(NODE_GYP_MODULE_NAME, init)

}  // namespace cityhash
