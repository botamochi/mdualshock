//
// DualShock Library
//
// created: 2013/10/23
//
#include <avr/io.h>
#include <util/delay.h>
#include "dualshock-drive.h"

// delay time between bytes [us]
#define DUALSHOCK_DELAY_TIME 200

// select pin control register
#define DUALSHOCK_DRIVE_PORT    PORTB
#define DUALSHOCK_DRIVE_DDR     DDRB
#define DUALSHOCK_DRIVE_PIN     PINB
#define DUALSHOCK_DRIVE_PIN_SEL PB2


// ----- Initialize -----
void dualshock_drive_init()
{
  // Using SPI
  // SPI Master mode
  // LSB first
  // SPI Clock mode 3
  // SCK = F_CPU / 128
  SPCR = _BV(SPE)|_BV(DORD)|_BV(CPOL)|_BV(CPHA)_BV(SPR1)|_BV(SPR0);
  SPSR = 0;

  // Select pin initialize
  DUALSHOCK_DRIVE_PORT |= _BV(DUALSHOCK_DRIVE_PIN_SEL);
  DUALSHOCK_DRIVE_DDR |= _BV(DUALSHOCK_DRIVE_PIN_SEL);
}


// ----- Begin communicate -----
void dualshock_drive_begin()
{
  DUALSHOCK_DRIVE_PORT &= ~_BV(DUALSHOCK_DRIVE_PIN_SEL);
}


// ----- End communicate -----
void dualshock_drive_end()
{
  DUALSHOCK_DRIVE_PORT |= _BV(DUALSHOCK_DRIVE_PIN_SEL);
}


// ----- Put and Get one byte -----
unsigned char dualshock_drive_put_get(unsigned char dat)
{
  unsigned char res;
  SPDR = dat;
  while (!(SPSR & _BV(SPIF)));
  res = SPDR;
  _delay_us(DUALSHOCK_DRIVE_DELAY_TIME);
  return res;
}
