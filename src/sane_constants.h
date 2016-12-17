#ifndef SANE_CONSTANTS_H
#define SANE_CONSTANTS_H

#include <sane/sane.h>
#include <node.h>
#include "nan.h"

using v8::Handle;
using v8::Object;

void InitSaneConstants(Handle<Object> exports);

#endif /* SANE_CONSTANTS_H */
