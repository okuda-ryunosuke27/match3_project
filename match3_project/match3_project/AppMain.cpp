/*********************************
�v���O���~���O���K
�}�b�`3�Q�[������
*********************************/
#include "DxLib.h"
#include "FreamControl.h"
#include "InputControl.h"
#include "SceneManager.h"


/*********************************
�}�N����`
*********************************/
#define SCREEN_HEIGHT (480)		//�X�N���[���T�C�Y(����)
#define SCREEN_WIDTH (640)		//�X�N���[���T�C�Y(��)
#define SCREEN_COLORBIT (32)	//�X�N���[���J���[�r�b�g
#define FONT_SIZE (20)			//�����T�C�Y

/*********************************
�^��`
*********************************/


/*********************************
�O���[�o���ϐ��錾
*********************************/


/*********************************
�v���g�^�C�v�錾
*********************************/

/*********************************
�v���O�����̊J�n
*********************************/
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{

	//�E�B���h�^�C�g���ݒ�
	SetMainWindowText("Match 3 Puzzle");

	//�E�B���h�E���[�h�ŋN��
	ChangeWindowMode(TRUE);
}