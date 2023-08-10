#include "GameMainScene.h"
#include "DxLib.h"
#include "Stage.h"
#include "SceneManager.h"

/*********************************
マクロ定義
*********************************/
#define TIMELIMIT			(3600 * 3)		//制限時間
#define NUMBER_IMAGE_MAX	(10)			//数字画像数

/*********************************
型定義
*********************************/



/*********************************
変数宣言
*********************************/
int GameScore;
int GameLevel;
int GameMission;
int GameTime;
int GameCount;						//初期化されないようにするためのカウント
int ReStartFlag;

int NumberImage[NUMBER_IMAGE_MAX];	//数字用画像


/*********************************
ゲームメイン画面：初期化処理
引数：なし
戻り値：エラー情報
*********************************/
int GameMainScene_Initialize()
{
	int ret = 0;
	int i;

	//画像の読込み
	LoadDivGraph("images/number.png", NUMBER_IMAGE_MAX, NUMBER_IMAGE_MAX, 1, 60, 120, NumberImage);

	//ステージ機能初期化
	ret = StageInitialize();

	//エラーチェック
	for ( i = 0; i < NUMBER_IMAGE_MAX; i++)
	{
		if (NumberImage[i] == D_ERROR)
		{
			ret = D_ERROR;
			break;
		}
	}

	//ゲームプレイが初回かどうか
	if (GameCount == 0)
	{
		GameScore = 0;			//スコアの初期化
		GameLevel = 1;			//ゲームレベルの初期化
		Set_StageMission(3);	//ミッションの初期化
		GameCount++;			//次回の設定
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
ゲームメイン画面：更新処理
引数：なし
戻り値：なし
*********************************/
void GameMainScene_Update()
{
	switch (Get_StageState())
	{
		case 0:
			SelectBlock();		//ブロックの選択する
			break;
		case 1:
			MoveBlock();		//ブロックを移動させる
			break;
		case 2:
			CheckBlock();		//ブロックの確認
			break;
		case 3:
			CheckClear();		//クリアチェック
			break;
		default:
			break;
	}

	//制限時間の更新
	GameTime--;

	//制限時間がなくなったら、ゲームオーバーに遷移する
	if (GameTime < 0)
	{
		Change_Scene(E_GAME_OVER);
	}

	//ミッションを達成したら、ゲームクリアに遷移する
	if (Get_StageClearFlag())
	{
		Change_Scene(E_GAME_CLEAR);
	}
}

/*********************************
ゲームメイン画面：初期化処理
引数：なし
戻り値：なし
*********************************/
void GameMainScene_Draw()
{

}