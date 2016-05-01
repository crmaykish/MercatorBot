#ifndef SERIAL_H_
#define SERIAL_H_

void serialInit();
void serialTransmit(char b);
void serialTransmitString(char b[]);
void serialTrasmitInt(int b);

#endif /* SERIAL_H_ */