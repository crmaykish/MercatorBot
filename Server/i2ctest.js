var i2c = require('i2c-bus'), i2c1 = i2c.openSync(1);

(function() {
	i2c1.sendByteSync(0x04, 5);
	console.log("yup");
	i2c1.closeSync();
}());