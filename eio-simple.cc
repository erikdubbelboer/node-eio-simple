
#include <v8.h>
#include <node.h>


using namespace v8;
using namespace node;


Handle<Value> SetMinParallel(const Arguments& args) {
  HandleScope scope;

  if (args.Length() < 1 || !args[0]->IsUint32()) {
    return ThrowException(Exception::TypeError(String::New("Expected number of threads")));
  }

  eio_set_min_parallel(args[0]->Uint32Value());

  return scope.Close(Undefined());
}

Handle<Value> SetMaxParallel(const Arguments& args) {
  HandleScope scope;

  if (args.Length() < 1 || !args[0]->IsUint32()) {
    return ThrowException(Exception::TypeError(String::New("Expected number of threads")));
  }

  eio_set_max_parallel(args[0]->Uint32Value());

  return scope.Close(Undefined());
}

Handle<Value> SetMaxIdle(const Arguments& args) {
  HandleScope scope;

  if (args.Length() < 1 || !args[0]->IsUint32()) {
    return ThrowException(Exception::TypeError(String::New("Expected number of threads")));
  }

  eio_set_max_idle(args[0]->Uint32Value());

  return scope.Close(Undefined());
}

Handle<Value> SetIdleTimeout(const Arguments& args) {
  HandleScope scope;

  if (args.Length() < 1 || !args[0]->IsUint32()) {
    return ThrowException(Exception::TypeError(String::New("Expected number of seconds")));
  }

  eio_set_idle_timeout(args[0]->Uint32Value());

  return scope.Close(Undefined());
}

Handle<Value> Usage(const Arguments& args) {
  HandleScope scope;

  Local<Object> info = Object::New();
  info->Set(String::NewSymbol("requests"), Integer::NewFromUnsigned(eio_nreqs()));
  info->Set(String::NewSymbol("ready"), Integer::NewFromUnsigned(eio_nready()));
  info->Set(String::NewSymbol("pending"), Integer::NewFromUnsigned(eio_npending()));
  info->Set(String::NewSymbol("threads"), Integer::NewFromUnsigned(eio_nthreads()));

  return scope.Close(info);
}


extern "C" void init(Handle<Object> target) {
  NODE_SET_METHOD(target, "setMinParallel", SetMinParallel);
  NODE_SET_METHOD(target, "setMaxParallel", SetMaxParallel);
  NODE_SET_METHOD(target, "setMaxIdle", SetMaxIdle);
  NODE_SET_METHOD(target, "setIdleTimeout", SetIdleTimeout);
  NODE_SET_METHOD(target, "usage", Usage);
}

