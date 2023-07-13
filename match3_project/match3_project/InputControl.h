#pragma once
/*********************************
マクロ定義
*********************************/


/*********************************
型定義
*********************************/


/*********************************
プロトタイプ宣言
*********************************/
void Input_Initialize(void);	//入力初期化
void Input_Update(void);		//入力更新
int Input_Escape(void);			//エスケープキーの入力

int GetOldKey(int key);			//過去押されていたキー
int GetNowKey(int key);			//現在押されているキー
int GetKeyFlg(int key);			//キーが押されているか
int GetMousePositionX(int key);	//マウスポイントのX
int GetMousePositionY(int key);	//マウスポイントのY