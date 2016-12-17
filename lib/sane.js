var SaneError = require("./sane_error");
var SaneDeviceOptionDescriptor = require("./sane_device_option_descriptor");
var SaneDevice = require("./sane_device");

function Sane() {
  const self = this;
  self.backend = Sane.backend;
  self.deviceCache = null;

  self.backend.init();

  self.getDevicesSync = function(options) {
    options = options == null ? {} : options;
    if(self.deviceCache == null || options.disableCache === true) {
      var result = self.backend.getDevicesSync(options.localOnly === true ? true : false);
      if(result.status != 0) {
        throw new SaneError(result.status);
      } else {
        self.deviceCache = SaneDevice.convertRaw(self, result.deviceList);
      }
    }
    return self.deviceCache;
  };

  self.getDevices = function(options, cb) {
    options = options == null ? {} : options;
    var promise = new Promise((resolve, reject) => {
      if(!self.disableCache && self.deviceCache != null) {
        return resolve(self.deviceCache);
      }
      self.backend.getDevices(options.localOnly, (result) => {
        if(result.status !== 0) {
          return reject(new SaneError(result.status));
        }
        self.deviceCache = SaneDevice.convertRaw(self, result.deviceList);
        return resolve(self.deviceCache);
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

  self.getNamedDevice = function(name) {
    return new SaneDevice(self, {name: name});
  };
}

module.exports = Sane;
