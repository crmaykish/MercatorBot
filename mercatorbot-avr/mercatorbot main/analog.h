#ifndef ANALOG_H_
#define ANALOG_H_

#include <avr/io.h>

void analogInit();
uint16_t analogRead(uint16_t channel);

#endif /* ANALOG_H_ */