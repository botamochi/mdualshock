//
// Dualshock Library
//
// created: 2013/10/23
//
#include "dualshock.h"
#include "dualshock-drive.h"

// �R�}���h����уX�e�[�^�X�R�[�h
#define DUALSHOCK_COMMAND_START      0x01
#define DUALSHOCK_COMMAND_GET_DATA   0x42
#define DUALSHOCK_COMMAND_SET_CONFIG 0x43
#define DUALSHOCK_COMMAND_SET_MODE   0x44
#define DUALSHOCK_COMMAND_STATUS_OK  0x5A

// ----- ���������� -----
void dualshock_init()
{
  dualshock_drive_init();
}


// ----- �{�^�����̏�Ԏ擾 -----
// �߂�l0: ����I��
// ���̑�: �G���[
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
  
  num = (id & 0x0F) ? (id & 0x0F) * 2 + 1 : 32; // �f�[�^�o�C�g��
  buf[0] = id;
  for (i = 1; i < num; i++) {
    buf[i] = dualshock_drive_put_get( 0x00 );
  }
  return 0;
}
