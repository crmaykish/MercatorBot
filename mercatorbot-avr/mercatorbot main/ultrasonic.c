#include "ultrasonic.h"
#include "robot.h"
#include "bitmacros.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>

void ultrasonicInit() {
	// Set triggers as output, leave echos as input
	DDRC |= bitValue(TRIG1);
	DDRC |= bitValue(TRIG2);
	DDRC |= bitValue(TRIG3);

	clearBit(PORTC, TRIG1);
	clearBit(PORTC, TRIG2);
	clearBit(PORTC, TRIG3);

	// Pull-up resistors?
	//PORTC |= bitValue(ECHO1);
	//PORTC |= bitValue(ECHO2);
	//PORTC |= bitValue(ECHO3);

	// Mask for PCIE2 interrupt
	PCMSK2 |= bitValue(ECHO1);
	PCMSK2 |= bitValue(ECHO2);
	PCMSK2 |= bitValue(ECHO3);

	// Enable interrupt PCIE2 (PCINT23:16)
	PCICR |= bitValue(PCIE2);

	// Enable global interrupts
	sei();
}

ISR(PCINT2_vect) {
	printf("interrupt!");
	printf((PINC & bitValue(PC2)) == 1 ? "high" : "low");
	printf("\n");
}