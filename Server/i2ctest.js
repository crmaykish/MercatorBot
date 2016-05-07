var i2c = require('i2c-bus'), i2c1 = i2c.openSync(1);

const ADDR = 0x04;

(function() {
	console.log("Starting");
	for (var i = 0; i < 10; i++) {
		i2c1.sendByteSync(ADDR, 5);	
	}
	i2c1.closeSync();
	console.log("Done");
}());