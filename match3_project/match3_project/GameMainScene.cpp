#include "GameMainScene.h"
#include "DxLib.h"
#include "Stage.h"
#include "SceneManager.h"

/*********************************
�}�N����`
*********************************/
#define TIMELIMIT			(3600 * 3)		//��������
#define NUMBER_IMAGE_MAX	(10)			//�����摜��

/*********************************
�^��`
*********************************/



/*********************************
�ϐ��錾
*********************************/
int GameScore;
int GameLevel;
int GameMission;
int GameTime;
int GameCount;						//����������Ȃ��悤�ɂ��邽�߂̃J�E���g
int ReStartFlag;

int NumberImage[NUMBER_IMAGE_MAX];	//�����p�摜


/*********************************
�Q�[�����C����ʁF����������
�����F�Ȃ�
�߂�l�F�G���[���
*********************************/
int GameMainScene_Initialize()
{
	int ret = 0;
	int i;

	//�摜�̓Ǎ���
	LoadDivGraph("images/number.png", NUMBER_IMAGE_MAX, NUMBER_IMAGE_MAX, 1, 60, 120, NumberImage);

	//�X�e�[�W�@�\������
	ret = StageInitialize();

	//�G���[�`�F�b�N
	for ( i = 0; i < NUMBER_IMAGE_MAX; i++)
	{
		if (NumberImage[i] == D_ERROR)
		{
			ret = D_ERROR;
			break;
		}
	}

	//�Q�[���v���C�����񂩂ǂ���
	if (GameCount == 0)
	{
		GameScore = 0;			//�X�R�A�̏�����
		GameLevel = 1;			//�Q�[�����x���̏�����
		Set_StageMission(3);	//�~�b�V�����̏�����
		GameCount++;			//����̐ݒ�
	}
	else
	{
		GameLevel++;
		Set_StageMission(3);
	}
	GameTime = TIMELIMIT;

	return ret;
}

/*********************************
�Q�[�����C����ʁF�X�V����
�����F�Ȃ�
�߂�l�F�Ȃ�
*********************************/
void GameMainScene_Update()
{
	switch (Get_StageState())
	{
		case 0:
			SelectBlock();		//�u���b�N�̑I������
			break;
		case 1:
			MoveBlock();		//�u���b�N���ړ�������
			break;
		case 2:
			CheckBlock();		//�u���b�N�̊m�F
			break;
		case 3:
			CheckClear();		//�N���A�`�F�b�N
			break;
		default:
			break;
	}

	//�������Ԃ̍X�V
	GameTime--;

	//�������Ԃ��Ȃ��Ȃ�����A�Q�[���I�[�o�[�ɑJ�ڂ���
	if (GameTime < 0)
	{
		Change_Scene(E_GAME_OVER);
	}

	//�~�b�V������B��������A�Q�[���N���A�ɑJ�ڂ���
	if (Get_StageClearFlag())
	{
		Change_Scene(E_GAME_CLEAR);
	}
}

/*********************************
�Q�[�����C����ʁF����������
�����F�Ȃ�
�߂�l�F�Ȃ�
*********************************/
void GameMainScene_Draw()
{

}