var SaneError = require("./sane_error");

function SaneDeviceOptionDescriptor(saneDevice, index, descriptor) {
  const self = this;
  self.saneDevice = saneDevice;
  self.index = index;
  self.descriptor = descriptor;

  Object.keys(self.descriptor).forEach((key) => {
    var value = self.descriptor[key];
    key = key == "descr" ? "description" : (key == null ? "" : key);
    self[key] = value;
  });

  self.getValue = function() {
    var buf = new Buffer(new ArrayBuffer(self.descriptor != null && self.descriptor.size > 0 ? self.descriptor.size : 8192));
    var status = self.saneDevice.sane.backend.controlOption(
      self.saneDevice.handle,
      self.index,
      self.saneDevice.sane.backend.Action.GET_VALUE,
      buf,
      self.type === self.saneDevice.sane.backend.ValueType.STRING
    );
    if(status != 0) throw new SaneError(status);
    return buf;
  };

  self.getJsValue = function() {
    var buf = self.getValue();
    if(self.type == self.saneDevice.sane.backend.ValueType.BOOL) {
      var value = buf.readUInt32BE();
      return value === self.saneDevice.sane.backend.BoolValue.TRUE ? true : false;
    } else if(self.type == self.saneDevice.sane.backend.ValueType.INT) {
      var value = buf.readUInt32BE();
      return value;
    } else if(self.type == self.saneDevice.sane.backend.ValueType.FIXED) {
      var value = buf.readUInt32BE();
      return self.saneDevice.sane.backend.fixedToNumber(value);
    } if(self.type == self.saneDevice.sane.backend.ValueType.STRING) {
      var value = buf.toString();
      return value;
    } else {
      return null;
    }
  }

  self.setValue = function(value) {
    var buf = new Buffer(value);
    var status = self.saneDevice.sane.backend.controlOption(
      self.saneDevice.handle,
      self.index,
      self.saneDevice.sane.backend.Action.SET_VALUE,
      buf
    );
    if(status != 0) throw new SaneError(status);
  };

  self.setAutoValue = function() {
    var buf = new Buffer(new ArrayBuffer(0));
    var status = self.saneDevice.sane.backend.controlOption(
      self.saneDevice.handle,
      self.index,
      self.saneDevice.sane.backend.Action.SET_AUTO,
      buf
    );
    if(status != 0) throw new SaneError(status);
  };
};

module.exports = SaneDeviceOptionDescriptor;
