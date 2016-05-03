#define F_CPU 16000000UL

#include "bitmacros.h"
#include "serial.h"
#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>

#define LED PD6
#define SWITCH PD7
#define POT PA7

int num = 0;

void setup() {
	// Set up digital IO
	setBit(DDRD, LED);
	clearBit(DDRD, SWITCH);

	serialInit();
	stdout = &uartOut;
}

void loop() {
	printf("hello %d \n", num);
	num++;
	_delay_ms(300);
}

int main(void) {
	setup();

	while (1) {
		loop();
	}
}