const path = require("path");
const fs = require("fs-extra");
const os = require("os");

const Sane = require("../index");
const SaneDevice = require("../lib/sane_device");

const minimist = require("minimist");
var argv = minimist(process.argv.slice(2));

var sane = new Sane();

function readDeviceCache() {
  var cacheFilePath = path.join(os.homedir(), ".scantooljs", "devices.cache");
  if(fs.existsSync(cacheFilePath)) {
    var data = fs.readFileSync(cacheFilePath);
    data = JSON.parse(data);
    var result = [];
    data.forEach((item) => {
      var device = new SaneDevice(sane, item);
      result.push(device);
    });
    return result;
  }
  return null;
}

function writeDeviceCache(devices) {
  if(devices == null) return;

  var cacheFileDir = path.join(os.homedir(), ".scantooljs");
  var cacheFilePath = path.join(cacheFileDir, "devices.cache");
  fs.mkdirs(cacheFileDir);
  var data = [];
  devices.forEach((device) => {
    data.push({
      type: device.type,
      model: device.model,
      vendor: device.vendor,
      name: device.name
    });
  });
  var json = JSON.stringify(data);
  fs.writeFileSync(cacheFilePath, json);
}

function findDevice(name) {
  if(devices == null) return null;
  var result = null;
  devices.forEach((device) => {
    if(device.name == name) {
      result = device;
      return false;
    }
  });
}

var devices = null;
if((argv.cache !== false || argv.n !== true)) {
  devices = readDeviceCache();
}

if(argv["list-devices"] === true || argv.l === true) {
  if(devices == null) {
    var localRemote = argv["local-only"] ? "(local)" : "(local + remote)";
    process.stdout.write("Searching for available devices " + localRemote + " ... ");
    devices = sane.getDevicesSync({localOnly: argv["local-only"] });
    console.log("done");
    process.stdout.write("Writing device cache ... ");
    writeDeviceCache(devices);
    console.log("done");
  }
  console.log("\ndevices: \n");
  if(devices == null || devices.length < 1) {
    console.log("\tnone");
  } else {
    devices.forEach((device) => {
      console.log("\tname:   " + device.name);
      console.log("\ttype:   " + device.type);
      console.log("\tmodel:  " + device.model);
      console.log("\tvendor: " + device.vendor);
      console.log();
    });
  }
} else if(argv["show-options"]) {
  var device = findDevice(argv.name);
  if(device == null && devices.length > 0) device = devices[0];
  if(device == null) {
    if(argv.name == null) {
      console.error("Please provide a name with --name");
    } else {
      console.error("Could not find device with name: ", argv.name);
    }
    process.exit();
  } else {
    device.openSync();
    console.log("options for device " + device.name + "\n");
    var descs = device.getOptionDescriptors();
    if(descs == null || descs.length < 1) {
      console.log("\tnone");
    } else {
      descs.forEach((desc) => {
        console.log("\tname:            " + desc.name);
        console.log("\ttitle:           " + desc.title);
        console.log("\tdescription:     " + desc.description);
        console.log("\ttype:            " + sane.backend.ValueType.shortName(desc.type));
        console.log("\tunit:            " + sane.backend.Unit.shortName(desc.unit));
        console.log("\tsize:            " + desc.size);
        console.log("\tcap:             " + desc.cap + " (" + sane.backend.Cap.asFlagNames(desc.cap) + ")");
        console.log("\tconstraint type: " + sane.backend.ConstraintType.shortName(desc.constraintType));
        console.log("\tconstraint:     ", desc.constraint);
        try {
          console.log("\tcurrent value:  ", desc.getJsValue());
        } catch(ex) {
          var status = ex.saneStatus != null ? sane.backend.Status.shortName(ex.saneStatus) : ex;
          console.log("\tcurrent value:   not readable (", status, ")");
        }
        console.log();
      });
    }
  }
} else if(argv.scan) {
  console.log("trying to scan ...");
  var device = findDevice(argv.name);
  if(device == null && devices.length > 0) device = devices[0];
  if(device == null) {
    if(argv.name == null) {
      console.error("Please provide a name with --name");
    } else {
      console.error("Could not find device with name: ", argv.name);
    }
    process.exit();
  }
  try {
    device.openSync();
    device.start();
    var buf = new Buffer(new ArrayBuffer(100 * 1024 * 1024));
    var result = null;
    var total = 0;
    var firstFrame = true;
    while((result = device.readSync(buf)) != null && result.status === 0) {
      total += result.length;
      if(firstFrame) {
        firstFrame = false;
        var params = device.getParameters();
        console.log("parameters for first frame: ", params);
      }
    }
    console.log("total bytes read: ", total);
    device.closeSync();
  } catch(ex) {
    console.error("Error: ", ex);
  }
}
