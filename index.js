'use strict';
const binary = require('node-pre-gyp');
const path = require('path');
const bindingPath = binary.find(path.resolve(path.join(__dirname, './package.json')));
const sane = require(bindingPath);
const Sane = require("./lib/sane");
Sane.backend = sane;
module.exports = Sane;

function keyForValue(obj, value) {
  var result = null;
  Object.keys(obj).forEach((key) => {
    if(value == obj[key]) {
      result = key;
      return false;
    }
  });
  return result == null ? "(unknown)" : result;
}

sane.Status.shortName = function(status) {
  return keyForValue(sane.Status, status);
}

sane.ValueType.shortName = function(valueType) {
  return keyForValue(sane.ValueType, valueType);
}

sane.Unit.shortName = function(unit) {
  return keyForValue(sane.Unit, unit);
}

sane.Cap.shortName = function(cap) {
  return keyForValue(sane.Cap, cap);
}

sane.Cap.asFlags = function(cap) {
  var flags = [];
  Object.keys(sane.Cap).forEach((key) => {
    var value = sane.Cap[key];
    if(typeof(value) == "number") {
      //console.log("cap " + cap + " has flag " + value + " set: ", (cap & value));
      if((cap & value) > 0) {
        flags.push(value);
      }
    }
  });
  return flags;
}

sane.Cap.asFlagNames = function(cap) {
  var flags = [];
  Object.keys(sane.Cap).forEach((key) => {
    var value = sane.Cap[key];
    if(typeof(value) == "number") {
      if((cap & value) > 0) {
        flags.push(key);
      }
    }
  });
  return flags;
}

sane.ConstraintType.shortName = function(ct) {
  return keyForValue(sane.ConstraintType, ct);
}

sane.Action.shortName = function(action) {
  return keyForValue(sane.Action, action);
}

sane.Info.shortName = function(info) {
  return keyForValue(sane.Info, info);
}

sane.Frame.shortName = function(frame) {
  return keyForValue(sane.Frame, frame);
}

/*
sane.Status = {
  GOOD          : 0,
  UNSUPPORTED   : 1,
  CANCELLED     : 2,
  DEVICE_BUSY   : 3,
  INVAL         : 4,
  EOF           : 5,
  JAMMED        : 6,
  NO_DOCS       : 7,
  COVER_OPEN    : 8,
  IO_ERROR      : 9,
  NO_MEM        : 10,
  ACCESS_DENIED : 11
};
Object.freeze(sane.Status);

sane.ValueType = {
  BOOL   : 0,
  INT    : 1,
  FIXED  : 2,
  STRING : 3,
  BUTTON : 4,
  GROUP  : 5
};
Object.freeze(sane.ValueType);

sane.Unit = {
  NONE        : 0,
  PIXEL       : 1,
  BIT         : 2,
  MM          : 3,
  DPI         : 4,
  PERCENT     : 5,
  MICROSECOND : 6
};
Object.freeze(sane.Unit);

sane.Cap = {
  SOFT_SELECT : 1,
  HARD_SELECT : 2,
  SOFT_DETECT : 4,
  EMULATED    : 8,
  AUTOMATIC   : 16,
  INACTIVE    : 32,
  ADVANCED    : 64
};
Object.freeze(sane.Cap);

sane.ConstraintType = {
  NONE        : 0,
  RANGE       : 1,
  WORD_LIST   : 2,
  STRING_LIST : 3
};
Object.freeze(sane.ConstraintType);

sane.Action = {
  GET_VALUE : 0,
  SET_VALUE : 1,
  SET_AUTO  : 2
};
Object.freeze(sane.Action);

sane.Info = {
  INEXACT        : 1,
  RELOAD_OPTIONS : 2,
  RELOAD_PARAMS  : 4
};
Object.freeze(sane.Info);

sane.FrameXXX = {
  GRAY  : 0,
  RGB   : 1,
  RED   : 2,
  GREEN : 3,
  BLUE  : 4
};
Object.freeze(sane.Frame);
*/
