#define F_CPU 16000000UL

#include "bitmacros.h"
#include "serial.h"
#include "analog.h"
#include "nrf24l01.h"
#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>

#define CE	PB3;
#define CSN	PB4;

char SPIWriteByte(unsigned char b) {
	SPDR = b;
	while (!(SPSR & bitValue(SPIF)));
	return SPDR;
}

uint8_t getRegister(uint8_t reg) {
	_delay_us(10);
	clearBit(PORTB, CSN);
	_delay_us(10);
	SPIWriteByte(R_REGISTER + reg);
	_delay_us(10);
	reg = SPIWriteByte(NOP);
	_delay_us(10);
	setBit(PORTB, CSN);
	return reg;
}

void writeToNRF(uint8_t reg, uint8_t package) {
	_delay_us(10);
	clearBit(PORTB, CSN);
	_delay_us(10);
	SPIWriteByte(W_REGISTER + reg);
	_delay_us(10);
	SPIWriteByte(package);
	_delay_us(10);
	setBit(PORTB, CSN);
}

void setup() {
	analogInit();
	serialInit();
	stdout = &uartOut;

	// SCK pin
	DDRB |= bitValue(PB7);

	// MOSI pin
	DDRB |= bitValue(PB5);

	// NRF CE pin
	DDRB |= bitValue(CE);

	// NRF CSN pin
	DDRB |= bitValue(CSN);

	setBit(PORTB, CSN);
	clearBit(PORTB, CE);
}

void loop() {
	
}

int main(void) {
	setup();

	while (1) {
		loop();
	}
}