function SaneError(status) {
  const self = this;
  self.saneStatus = status;

  Error.call(self, "Sane error: " + status);
}

module.exports = SaneError;
