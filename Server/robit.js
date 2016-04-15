var app = require('express')();
var http = require('http').Server(app);
var io = require('socket.io')(http);

var serialport = require('serialport');
SerialPort = serialport.SerialPort;

var jsonVal = "";

var port = new SerialPort("/dev/ttyUSB0", {
    baudRate: 9600,
    parser: serialport.parsers.readline("\n")
});

port.on("open", function() {
    console.log("Connected to serial.");
});

port.on("data", function(data) {
    if (data.substring(0,1) == '{'){
        jsonVal = JSON.parse(data);
        io.emit('chat message', jsonVal);
    } else {
        console.log("Bad JSON: " + data);
    }
});

app.get('/', function(req, res) {
    res.sendFile(__dirname + '/index.html');
});

io.on('connection', function(socket) {
	console.log("User connected.");

	socket.on('disconnect', function(){
		console.log("User disconnected");
	});
});

http.listen(3000, function() {
    console.log("Server started");
});