//
// DualShock Library
// ATmega8系 SPIペリフェラル使用
//
// created: 2013/10/23
//
#include <avr/io.h>
#include <util/delay.h>
#include "dualshock-drive.h"

// 通信時の1byte間の間隔(単位:us)
#define DUALSHOCK_DELAY_TIME 200

// SPI SEL端子制御用
#define DUALSHOCK_DRIVE_PORT    PORTB
#define DUALSHOCK_DRIVE_DDR     DDRB
#define DUALSHOCK_DRIVE_PIN     PINB
#define DUALSHOCK_DRIVE_PIN_SEL PB2


// ----- 初期化処理 -----
void dualshock_drive_init()
{
  // Using SPI
  // SPI Master mode
  // LSB first
  // SPI Clock mode 3
  // SCK = F_CPU / 128
  SPCR = _BV(SPE)|_BV(DORD)|_BV(CPOL)|_BV(CPHA)_BV(SPR1)|_BV(SPR0);
  SPSR = 0;

  // SEL端子制御ポート初期化
  DUALSHOCK_DRIVE_PORT |= _BV(DUALSHOCK_DRIVE_PIN_SEL);
  DUALSHOCK_DRIVE_DDR |= _BV(DUALSHOCK_DRIVE_PIN_SEL);
}


// ----- SEL端子Low出力 -----
void dualshock_drive_begin()
{
  DUALSHOCK_DRIVE_PORT &= ~_BV(DUALSHOCK_DRIVE_PIN_SEL);
}


// ----- SEL端子High出力 -----
void dualshock_drive_end()
{
  DUALSHOCK_DRIVE_PORT |= _BV(DUALSHOCK_DRIVE_PIN_SEL);
}


// ----- 1byte送受信&待機 -----
unsigned char dualshock_drive_put_get(unsigned char dat)
{
  unsigned char res;
  SPDR = dat;
  while (!(SPSR & _BV(SPIF)));
  res = SPDR;
  _delay_us(DUALSHOCK_DRIVE_DELAY_TIME);
  return res;
}
