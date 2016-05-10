#define F_CPU 16000000UL

#include "bitmacros.h"
#include "robot.h"
#include "serial.h"
#include "analog.h"
#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>

int counter = 0;

void setup() {
	analogInit();
	serialInit();

	// Redirect stdout to the UART
	stdout = &uartOut;
}

void loop() {
	printf("Hello, Robo! %d\n", counter);
	counter++;
	_delay_ms(1000);
}

int main(void) {
	setup();

	while (1) {
		loop();
	}
}