//
// Dualshock Library
//
// created: 2013/10/23
//
#include "dualshock.h"
#include "dualshock-drive.h"

// コマンドおよびステータスコード
#define DUALSHOCK_COMMAND_START      0x01
#define DUALSHOCK_COMMAND_GET_DATA   0x42
#define DUALSHOCK_COMMAND_SET_CONFIG 0x43
#define DUALSHOCK_COMMAND_SET_MODE   0x44
#define DUALSHOCK_COMMAND_STATUS_OK  0x5A

// ----- 初期化処理 -----
void dualshock_init()
{
  dualshock_drive_init();
}


// ----- ボタン等の状態取得 -----
// 戻り値0: 正常終了
// その他: エラー
int dualshock_get_data(DualshockData *dat)
{
  unsigned char i, num, id, res;
  unsigned char *buf = (unsigned char *)dat;

  dualshock_drive_put_get( DUALSHOCK_COMMAND_START );
  id = dualshock_drive_put_get( DUALSHOCK_COMMAND_GET_DATA );
  res = dualshock_drive_put_get( 0x00 );
  if (res != DUALSHOCK_COMMAND_STATUS_OK) {
    return 1;
  }
  
  num = (id & 0x0F) ? (id & 0x0F) * 2 + 1 : 32; // データバイト数
  buf[0] = id;
  for (i = 1; i < num; i++) {
    buf[i] = dualshock_drive_put_get( 0x00 );
  }
  return 0;
}
