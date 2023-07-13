/*********************************
プログラミング実習
マッチ3ゲーム制作
*********************************/
#include "DxLib.h"
#include "FreamControl.h"
#include "InputControl.h"
#include "SceneManager.h"


/*********************************
マクロ定義
*********************************/
#define SCREEN_HEIGHT (480)		//スクリーンサイズ(高さ)
#define SCREEN_WIDTH (640)		//スクリーンサイズ(幅)
#define SCREEN_COLORBIT (32)	//スクリーンカラービット
#define FONT_SIZE (20)			//文字サイズ

/*********************************
型定義
*********************************/


/*********************************
グローバル変数宣言
*********************************/


/*********************************
プロトタイプ宣言
*********************************/

/*********************************
プログラムの開始
*********************************/
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{

	//ウィンドタイトル設定
	SetMainWindowText("Match 3 Puzzle");

	//ウィンドウモードで起動
	ChangeWindowMode(TRUE);
}