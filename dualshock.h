//
// DualShock Library
// �v���X�ePAD�v���g�R���̎���
//
// created: 2013/10/23
//
#ifndef _LIB_DUALSHOCK_PROTOCOL_
#define _LIB_DUALSHOCK_PROTOCOL_

// �R���g���[���̃^�C�v(����ID���̂܂�)
#define DUALSHOCK_MODE_DIGITAL 0x41
#define DUALSHOCK_MODE_ANALOG  0x73

//----------------------------------------
// �R���g���[���f�[�^�\����
//----------------------------------------

// �{�^���f�[�^
// ������Ă���Ƃ��l��0
// ���g���G���f�B�A���Ȃ̂Œ���
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

// �X�e�B�b�N�f�[�^
// ���S�ł̒l��0x80
struct DualshockStick {
  unsigned char rx;
  unsigned char ry;
  unsigned char lx;
  unsigned char ly;
};

// ��M�f�[�^�p�\����
// �f�B�W�^�����[�h���̓X�e�B�b�N�̃f�[�^�͖���
typedef struct _tDualshockData {
  unsigned char          id; // response id
  struct DualshockButton button;
  struct DualshockStick  stick;
} DualshockData;


//----------------------------------------
// ���C�u�����֐�
//----------------------------------------
void dualshock_init(void);
int  dualshock_get_data(DualshockData *dat);

#endif
