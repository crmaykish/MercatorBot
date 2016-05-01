// Reference: http://maxembedded.com/2011/06/the-adc-of-the-avr/

#include "analog.h"
#include "bitmacros.h"
#include <avr/io.h>

void analogInit() {
	// Use AVCC pin for voltage reference
	ADMUX = bitValue(REFS0);

	// Set ADC prescalar to 125KHz at 16Mhz
	ADCSRA |= bitValue(ADPS2) | bitValue(ADPS1) | bitValue(ADPS0);

	// Enable ADC
	ADCSRA |= bitValue(ADEN);
}

uint16_t analogRead(uint16_t channel) {
	// Clear all but the bottom 3 bits to ensure channel <= 7
	channel &= 0b111;

	// Clear bottom 3 bits of ADMUX
	ADMUX &= 0x11111000;

	// Set ADC channel (bottom 3 bits of ADMUX)
	ADMUX |= channel;

	// Start ADC conversion
	ADCSRA |= bitValue(ADSC);

	// Wait for conversion to finish
	while (ADCSRA & bitValue(ADSC));

	// return result
	return (ADC);
}