//
// DualShock Library
// プレステPADプロトコルの実装
//
// created: 2013/10/23
//
#ifndef _LIB_DUALSHOCK_PROTOCOL_
#define _LIB_DUALSHOCK_PROTOCOL_

// コントローラのタイプ(応答IDそのまま)
#define DUALSHOCK_MODE_DIGITAL 0x41
#define DUALSHOCK_MODE_ANALOG  0x73

//----------------------------------------
// コントローラデータ構造体
//----------------------------------------

// ボタンデータ
// 押されているとき値が0
// リトルエンディアンなので注意
struct DualshockButton {
  unsigned char square : 1;
  unsigned char cross  : 1;
  unsigned char circle : 1;
  unsigned char delta  : 1;
  unsigned char right1 : 1;
  unsigned char left1  : 1;
  unsigned char right2 : 1;
  unsigned char left2  : 1;
  unsigned char left   : 1;
  unsigned char bottom : 1;
  unsigned char right  : 1;
  unsigned char top    : 1;
  unsigned char start  : 1;
  unsigned char right3 : 1;
  unsigned char select : 1;
};

// スティックデータ
// 中心での値が0x80
struct DualshockStick {
  unsigned char rx;
  unsigned char ry;
  unsigned char lx;
  unsigned char ly;
};

// 受信データ用構造体
// ディジタルモード時はスティックのデータは無効
typedef struct _tDualshockData {
  unsigned char          id; // response id
  struct DualshockButton button;
  struct DualshockStick  stick;
} DualshockData;


//----------------------------------------
// ライブラリ関数
//----------------------------------------
void dualshock_init(void);
int  dualshock_get_data(DualshockData *dat);

#endif
