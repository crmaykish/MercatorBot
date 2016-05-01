#define F_CPU 16000000UL

#include "serial.h"
#include "analog.h"
#include "bitmacros.h"
#include <avr/io.h>
#include <util/delay.h>

#define LED PD6
#define SWITCH PD7
#define POT PA7

void setup() {
	// Set up digital IO
	setBit(DDRD, LED);
	clearBit(DDRD, SWITCH);

	analogInit();
	serialInit();
}

void loop() {
	serialTrasmitInt(100);
	serialTransmit('\n');
	_delay_ms(400);
}

int main(void) {
	setup();

	while (1) {
		loop();
	}
}