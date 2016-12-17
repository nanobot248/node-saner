var SaneError = require("./sane_error");
var SaneDeviceOptionDescriptor = require("./sane_device_option_descriptor");

function SaneDevice(sane, options) {
  const self = this;
  self.sane = sane;
  self.type = options.type;
  self.model = options.model;
  self.vendor = options.vendor;
  self.name = options.name;
  self.handle = null;
  self.optionDescriptorCache = null;

  self.openSync = function() {
    if(self.handle == null) {
      var result = self.sane.backend.openSync(self.name);
      if(result.status != 0) { throw new SaneError(result.status) }
      self.handle = result.handle;
    }
  };

  self.open = function(cb) {
    var promise = new Promise((resolve, reject) => {
      self.sane.backend.open(self.name, (status) => {
        if(status == 0) {
          resolve();
        } else {
          reject(new SaneError(status));
        }
      });
    });
    if(cb == null) {
      return promise;
    } else {
      promise
        .then((devices) => { cb(null, devices); })
        .fail((err) => { cb(err); });
    }
  };

  self.closeSync = function() {
    if(self.handle != null) {
      self.sane.backend.closeSync(self.handle);
      self.handle = null;
    }
  };

  self.close = function(cb) {
    var promise = new Promise((resolve, reject) => {
      self.sane.backend.close(self.name, (status) => {
        if(status == null || status === 0) {
          resolve();
        } else {
          reject(new SaneError(status));
        }
      });
    });
    if(cb == null) {
      return promise;
    } else {
      promise
        .then((devices) => { cb(null, devices); })
        .fail((err) => { cb(err); });
    }
  };

  self.getOptionDescriptors = function(noCache) {
    if(self.handle == null) {
      throw new Error("Device must be opened first!");
    }
    if(self.optionDescriptorCache == null || noCache === true) {
      self.optionDescriptorCache = [];
      var current = null;
      for(var i = 0; (current = self.sane.backend.getOptionDescriptor(self.handle, i)) != null; i++) {
        current = new SaneDeviceOptionDescriptor(self, i, current);
        self.optionDescriptorCache.push(current);
      }
    }
    return self.optionDescriptorCache;
  };

  self.getParameters = function() {
    return self.sane.backend.getParameters(self.handle);
  };

  self.start = function() {
    return self.sane.backend.start(self.handle);
  }

  self.cancel = function() {
    return self.sane.backend.cancel(self.handle);
  }

  self.readSync = function(buf) {
    return self.sane.backend.readSync(self.handle, buf);
  }
}
SaneDevice.convertRaw = function(sane, saneDevices) {
  var result = [];
  if(saneDevices != null) {
    saneDevices.forEach((deviceInfos) => {
      result.push(new SaneDevice(sane, deviceInfos));
    });
  }
  return result;
};

module.exports = SaneDevice;
