#include "ultrasonic.h"
#include "robot.h"
#include "bitmacros.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>

void ultrasonicInit() {
	// Set trigger pins as output, leave echo pins as input
	DDRC |= bitValue(TRIG1);
	DDRC |= bitValue(TRIG2);
	DDRC |= bitValue(TRIG3);

	// Mask for PCIE2 interrupt
	PCMSK2 |= bitValue(ECHO1);
	PCMSK2 |= bitValue(ECHO2);
	PCMSK2 |= bitValue(ECHO3);

	// Enable interrupt PCIE2 (PORTC, PCINT23:16)
	PCICR |= bitValue(PCIE2);

	// Enable global interrupts
	sei();
}

ISR(PCINT2_vect) {
	int i = (PINC & bitValue(ECHO3)) >> ECHO3;
	printf("%s\n", i ? "high" : "low");
}