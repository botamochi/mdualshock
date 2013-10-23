//
// DualShock Library
// Drive Layer for ATmega168
// Using SPI Peripheral
//
// created: 2013/10/23
//
#ifndef _AVR_LIB_DUALSHOCK_DRIVE_
#define _AVR_LIB_DUALSHOCK_DRIVE_

void dualshock_drive_init(void);
void dualshock_drive_begin(void);
void dualshock_drive_end(void);
unsigned char dualshock_drive_put_get(unsigned char dat);

#endif
