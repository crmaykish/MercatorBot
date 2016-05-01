#include "serial.h"
#include "bitmacros.h"
#include <avr/io.h>

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#ifndef BAUD
#define BAUD 9600
#endif

#define MYUBRR ((F_CPU / 16 / BAUD) - 1)

void serialInit(int baud) {
	// Set baud rate
	UBRR0H = (unsigned char) (MYUBRR >> 8);
	UBRR0L = (unsigned char) MYUBRR;

	// Enable transmit and receive
	UCSR0B = bitValue(RXEN0) | bitValue(TXEN0);

	// Set frame format: 8data, 2stop bit
	UCSR0C = bitValue(USBS0) | (3 << UCSZ00);
}

void serialTransmit(char b) {
	while (!(UCSR0A & bitValue(UDRE0)));
	UDR0 = b;
}

void serialTransmitString(char b[]) {
	int i = 0;
	while (b[i] != '\0') {
		serialTransmit(b[i]);
		i++;
	}
}

// broken
void serialTrasmitInt(int b) {
	while (b > 0) {
		int n = b % 10;
		char c = '0' + n;
		serialTransmit(c);
		b = b / 10;
	}
}