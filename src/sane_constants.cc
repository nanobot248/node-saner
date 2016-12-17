#include "sane_constants.h"

using v8::Local;
using v8::String;
using v8::Handle;
using v8::Value;
using v8::Function;
using v8::FunctionTemplate;
using v8::Object;
using v8::External;

NAN_GETTER(GetSaneFrameGray) {
  info.GetReturnValue().Set(Nan::New(SANE_FRAME_GRAY));
}

NAN_GETTER(GetSaneFrameRgb) {
  info.GetReturnValue().Set(Nan::New(SANE_FRAME_RGB));
}

NAN_GETTER(GetSaneFrameRed) {
  info.GetReturnValue().Set(Nan::New(SANE_FRAME_RED));
}

NAN_GETTER(GetSaneFrameGreen) {
  info.GetReturnValue().Set(Nan::New(SANE_FRAME_GREEN));
}

NAN_GETTER(GetSaneFrameBlue) {
  info.GetReturnValue().Set(Nan::New(SANE_FRAME_BLUE));
}

NAN_GETTER(GetSaneTrue) {
  info.GetReturnValue().Set(Nan::New(SANE_TRUE));
}

NAN_GETTER(GetSaneFalse) {
  info.GetReturnValue().Set(Nan::New(SANE_FALSE));
}

NAN_GETTER(GetSaneStatusGood) {
  info.GetReturnValue().Set(Nan::New(SANE_STATUS_GOOD));
}

NAN_GETTER(GetSaneStatusUnsupported) {
  info.GetReturnValue().Set(Nan::New(SANE_STATUS_UNSUPPORTED));
}

NAN_GETTER(GetSaneStatusCancelled) {
  info.GetReturnValue().Set(Nan::New(SANE_STATUS_CANCELLED));
}

NAN_GETTER(GetSaneStatusDeviceBusy) {
  info.GetReturnValue().Set(Nan::New(SANE_STATUS_DEVICE_BUSY));
}

NAN_GETTER(GetSaneStatusInval) {
  info.GetReturnValue().Set(Nan::New(SANE_STATUS_INVAL));
}

NAN_GETTER(GetSaneStatusEof) {
  info.GetReturnValue().Set(Nan::New(SANE_STATUS_EOF));
}

NAN_GETTER(GetSaneStatusJammed) {
  info.GetReturnValue().Set(Nan::New(SANE_STATUS_JAMMED));
}

NAN_GETTER(GetSaneStatusNoDocs) {
  info.GetReturnValue().Set(Nan::New(SANE_STATUS_NO_DOCS));
}

NAN_GETTER(GetSaneStatusCoverOpen) {
  info.GetReturnValue().Set(Nan::New(SANE_STATUS_COVER_OPEN));
}

NAN_GETTER(GetSaneStatusIoError) {
  info.GetReturnValue().Set(Nan::New(SANE_STATUS_IO_ERROR));
}

NAN_GETTER(GetSaneStatusNoMem) {
  info.GetReturnValue().Set(Nan::New(SANE_STATUS_NO_MEM));
}

NAN_GETTER(GetSaneStatusAccessDenied) {
  info.GetReturnValue().Set(Nan::New(SANE_STATUS_ACCESS_DENIED));
}

NAN_GETTER(GetSaneTypeBool) {
  info.GetReturnValue().Set(Nan::New(SANE_TYPE_BOOL));
}

NAN_GETTER(GetSaneTypeInt) {
  info.GetReturnValue().Set(Nan::New(SANE_TYPE_INT));
}

NAN_GETTER(GetSaneTypeFixed) {
  info.GetReturnValue().Set(Nan::New(SANE_TYPE_FIXED));
}

NAN_GETTER(GetSaneTypeString) {
  info.GetReturnValue().Set(Nan::New(SANE_TYPE_STRING));
}

NAN_GETTER(GetSaneTypeButton) {
  info.GetReturnValue().Set(Nan::New(SANE_TYPE_BUTTON));
}

NAN_GETTER(GetSaneTypeGroup) {
  info.GetReturnValue().Set(Nan::New(SANE_TYPE_GROUP));
}

NAN_GETTER(GetSaneUnitNone) {
  info.GetReturnValue().Set(Nan::New(SANE_UNIT_NONE));
}

NAN_GETTER(GetSaneUnitPixel) {
  info.GetReturnValue().Set(Nan::New(SANE_UNIT_PIXEL));
}

NAN_GETTER(GetSaneUnitBit) {
  info.GetReturnValue().Set(Nan::New(SANE_UNIT_BIT));
}

NAN_GETTER(GetSaneUnitMm) {
  info.GetReturnValue().Set(Nan::New(SANE_UNIT_MM));
}

NAN_GETTER(GetSaneUnitDpi) {
  info.GetReturnValue().Set(Nan::New(SANE_UNIT_DPI));
}

NAN_GETTER(GetSaneUnitPercent) {
  info.GetReturnValue().Set(Nan::New(SANE_UNIT_PERCENT));
}

NAN_GETTER(GetSaneUnitMicroseconds) {
  info.GetReturnValue().Set(Nan::New(SANE_UNIT_MICROSECOND));
}


NAN_GETTER(GetSaneCapSoftSelect) {
  info.GetReturnValue().Set(Nan::New(SANE_CAP_SOFT_SELECT));
}

NAN_GETTER(GetSaneCapHardSelect) {
  info.GetReturnValue().Set(Nan::New(SANE_CAP_HARD_SELECT));
}

NAN_GETTER(GetSaneCapSoftDetect) {
  info.GetReturnValue().Set(Nan::New(SANE_CAP_SOFT_DETECT));
}

NAN_GETTER(GetSaneCapEmulated) {
  info.GetReturnValue().Set(Nan::New(SANE_CAP_EMULATED));
}

NAN_GETTER(GetSaneCapAutomatic) {
  info.GetReturnValue().Set(Nan::New(SANE_CAP_AUTOMATIC));
}

NAN_GETTER(GetSaneCapInactive) {
  info.GetReturnValue().Set(Nan::New(SANE_CAP_INACTIVE));
}

NAN_GETTER(GetSaneCapAdvanced) {
  info.GetReturnValue().Set(Nan::New(SANE_CAP_ADVANCED));
}

NAN_GETTER(GetSaneConstraintNone) {
  info.GetReturnValue().Set(Nan::New(SANE_CONSTRAINT_NONE));
}

NAN_GETTER(GetSaneConstraintRange) {
  info.GetReturnValue().Set(Nan::New(SANE_CONSTRAINT_RANGE));
}

NAN_GETTER(GetSaneConstraintWordList) {
  info.GetReturnValue().Set(Nan::New(SANE_CONSTRAINT_WORD_LIST));
}

NAN_GETTER(GetSaneConstraintStringList) {
  info.GetReturnValue().Set(Nan::New(SANE_CONSTRAINT_STRING_LIST));
}

NAN_GETTER(GetSaneActionGetValue) {
  info.GetReturnValue().Set(Nan::New(SANE_ACTION_GET_VALUE));
}

NAN_GETTER(GetSaneActionSetValue) {
  info.GetReturnValue().Set(Nan::New(SANE_ACTION_SET_VALUE));
}

NAN_GETTER(GetSaneActionSetAuto) {
  info.GetReturnValue().Set(Nan::New(SANE_ACTION_SET_AUTO));
}

NAN_GETTER(GetSaneInfoInexact) {
  info.GetReturnValue().Set(Nan::New(SANE_INFO_INEXACT));
}

NAN_GETTER(GetSaneInfoReloadOptions) {
  info.GetReturnValue().Set(Nan::New(SANE_INFO_RELOAD_OPTIONS));
}

NAN_GETTER(GetSaneInfoReloadParams) {
  info.GetReturnValue().Set(Nan::New(SANE_INFO_RELOAD_PARAMS));
}

void InitSaneConstants(Handle<Object> exports) {
  Local<Object> frame = Nan::New<Object>();
  Nan::Set(exports, Nan::New("Frame").ToLocalChecked(), frame);
  Nan::SetAccessor(frame, Nan::New("GRAY").ToLocalChecked(), GetSaneFrameGray);
  Nan::SetAccessor(frame, Nan::New("RGB").ToLocalChecked(),  GetSaneFrameRgb );
  Nan::SetAccessor(frame, Nan::New("RED").ToLocalChecked(),  GetSaneFrameRed );
  Nan::SetAccessor(frame, Nan::New("GREEN").ToLocalChecked(),  GetSaneFrameGreen );
  Nan::SetAccessor(frame, Nan::New("BLUE").ToLocalChecked(),  GetSaneFrameBlue );

  Local<Object> saneBool = Nan::New<Object>();
  Nan::Set(exports, Nan::New("BoolValue").ToLocalChecked(), saneBool);
  Nan::SetAccessor(saneBool, Nan::New("SANE_TRUE").ToLocalChecked(),  GetSaneTrue );
  Nan::SetAccessor(saneBool, Nan::New("SANE_FALSE").ToLocalChecked(),  GetSaneFalse );

  Local<Object> status = Nan::New<Object>();
  Nan::Set(exports, Nan::New("Status").ToLocalChecked(), status);
  Nan::SetAccessor(status, Nan::New("GOOD").ToLocalChecked(),  GetSaneStatusGood );
  Nan::SetAccessor(status, Nan::New("UNSUPPORTED").ToLocalChecked(),  GetSaneStatusUnsupported );
  Nan::SetAccessor(status, Nan::New("CANCELLED").ToLocalChecked(),  GetSaneStatusCancelled );
  Nan::SetAccessor(status, Nan::New("DEVICE_BUSY").ToLocalChecked(),  GetSaneStatusDeviceBusy );
  Nan::SetAccessor(status, Nan::New("INVAL").ToLocalChecked(),  GetSaneStatusInval );
  Nan::SetAccessor(status, Nan::New("EOF").ToLocalChecked(),  GetSaneStatusEof );
  Nan::SetAccessor(status, Nan::New("JAMMED").ToLocalChecked(),  GetSaneStatusJammed );
  Nan::SetAccessor(status, Nan::New("NO_DOCS").ToLocalChecked(),  GetSaneStatusNoDocs );
  Nan::SetAccessor(status, Nan::New("COVER_OPEN").ToLocalChecked(),  GetSaneStatusCoverOpen );
  Nan::SetAccessor(status, Nan::New("IO_ERROR").ToLocalChecked(),  GetSaneStatusIoError );
  Nan::SetAccessor(status, Nan::New("NO_MEM").ToLocalChecked(),  GetSaneStatusNoMem );
  Nan::SetAccessor(status, Nan::New("ACCESS_DENIED").ToLocalChecked(),  GetSaneStatusAccessDenied );

  Local<Object> type = Nan::New<Object>();
  Nan::Set(exports, Nan::New("ValueType").ToLocalChecked(), type);
  Nan::SetAccessor(type, Nan::New("BOOL").ToLocalChecked(),  GetSaneTypeBool );
  Nan::SetAccessor(type, Nan::New("INT").ToLocalChecked(),  GetSaneTypeInt );
  Nan::SetAccessor(type, Nan::New("FIXED").ToLocalChecked(),  GetSaneTypeFixed );
  Nan::SetAccessor(type, Nan::New("STRING").ToLocalChecked(),  GetSaneTypeString );
  Nan::SetAccessor(type, Nan::New("BUTTON").ToLocalChecked(),  GetSaneTypeButton );
  Nan::SetAccessor(type, Nan::New("GROUP").ToLocalChecked(),  GetSaneTypeGroup );

  Local<Object> unit = Nan::New<Object>();
  Nan::Set(exports, Nan::New("Unit").ToLocalChecked(), unit);
  Nan::SetAccessor(unit, Nan::New("NONE").ToLocalChecked(),  GetSaneUnitNone );
  Nan::SetAccessor(unit, Nan::New("PIXEL").ToLocalChecked(),  GetSaneUnitPixel );
  Nan::SetAccessor(unit, Nan::New("BIT").ToLocalChecked(),  GetSaneUnitBit );
  Nan::SetAccessor(unit, Nan::New("MM").ToLocalChecked(),  GetSaneUnitMm );
  Nan::SetAccessor(unit, Nan::New("DPI").ToLocalChecked(),  GetSaneUnitDpi );
  Nan::SetAccessor(unit, Nan::New("PERCENT").ToLocalChecked(),  GetSaneUnitPercent );
  Nan::SetAccessor(unit, Nan::New("MICROSECOND").ToLocalChecked(),  GetSaneUnitMicroseconds );

  Local<Object> cap = Nan::New<Object>();
  Nan::Set(exports, Nan::New("Cap").ToLocalChecked(), cap);
  Nan::SetAccessor(cap, Nan::New("SOFT_SELECT").ToLocalChecked(),  GetSaneCapSoftSelect );
  Nan::SetAccessor(cap, Nan::New("HARD_SELECT").ToLocalChecked(),  GetSaneCapHardSelect );
  Nan::SetAccessor(cap, Nan::New("SOFT_DETECT").ToLocalChecked(),  GetSaneCapSoftDetect );
  Nan::SetAccessor(cap, Nan::New("EMULATED").ToLocalChecked(),  GetSaneCapEmulated );
  Nan::SetAccessor(cap, Nan::New("AUTOMATIC").ToLocalChecked(),  GetSaneCapAutomatic );
  Nan::SetAccessor(cap, Nan::New("INACTIVE").ToLocalChecked(),  GetSaneCapInactive );
  Nan::SetAccessor(cap, Nan::New("ADVANCED").ToLocalChecked(),  GetSaneCapAdvanced );

  Local<Object> constraint = Nan::New<Object>();
  Nan::Set(exports, Nan::New("ConstraintType").ToLocalChecked(), constraint);
  Nan::SetAccessor(constraint, Nan::New("NONE").ToLocalChecked(),  GetSaneConstraintNone );
  Nan::SetAccessor(constraint, Nan::New("RANGE").ToLocalChecked(),  GetSaneConstraintRange );
  Nan::SetAccessor(constraint, Nan::New("WORD_LIST").ToLocalChecked(),  GetSaneConstraintWordList );
  Nan::SetAccessor(constraint, Nan::New("STRING_LIST").ToLocalChecked(),  GetSaneConstraintStringList );

  Local<Object> action = Nan::New<Object>();
  Nan::Set(exports, Nan::New("Action").ToLocalChecked(), action);
  Nan::SetAccessor(action, Nan::New("GET_VALUE").ToLocalChecked(),  GetSaneActionGetValue );
  Nan::SetAccessor(action, Nan::New("SET_VALUE").ToLocalChecked(),  GetSaneActionSetValue );
  Nan::SetAccessor(action, Nan::New("SET_AUTO").ToLocalChecked(),  GetSaneActionSetAuto );

  Local<Object> info = Nan::New<Object>();
  Nan::Set(exports, Nan::New("Info").ToLocalChecked(), info);
  Nan::SetAccessor(info, Nan::New("INEXACT").ToLocalChecked(),  GetSaneInfoInexact );
  Nan::SetAccessor(info, Nan::New("RELOAD_OPTIONS").ToLocalChecked(),  GetSaneInfoReloadOptions );
  Nan::SetAccessor(info, Nan::New("RELOAD_PARAMS").ToLocalChecked(),  GetSaneInfoReloadParams );
}
