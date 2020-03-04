#include "DxLib.h"
#include "Extern.h"

void SetColor() {
	color_white = GetColor(255, 255, 255);            //白色ハンドルを取得
	color_red = GetColor(255, 0, 0);
	color_black = GetColor(0, 0, 0);
	color_green = GetColor(0, 255, 0);
	color_blue = GetColor(0, 0, 255);
	color_yellow = GetColor(255, 255, 0);
	color_fuchsia = GetColor(255, 0, 255);
	color_aqua = GetColor(0, 255, 255);
	color_orange = GetColor(255, 127, 0);
	return;
}

void FpsTimeFanction() {
	static int FpsTime[2] = { 0, }, FpsTime_i = 0;
	static double Fps = 0.0;                          //静的変数宣言

	if (FpsTime_i == 0)
		FpsTime[0] = GetNowCount();               //1周目の時間取得
	if (FpsTime_i == 49) {
		FpsTime[1] = GetNowCount();               //50周目の時間取得
		Fps = 1000.0f / ((FpsTime[1] - FpsTime[0]) / 50.0f);//測定した値からfpsを計算
		FpsTime_i = 0;//カウントを初期化
	}
	else
		FpsTime_i++;//現在何周目かカウント
	if (Fps != 0)
		DrawFormatString(565, 460, color_white, "FPS %.1f", Fps); //fpsを表示
	return;
}

void FeeldSet(){
	static int i,j;
	for (i = 0; i < 12; i++) {
		for (j = 0; j < 22; j++) {
			if (i == 0 || i == 11 || j == 21)
				feeld[i][j] = 9;
			else
				feeld[i][j] = 0;
		}
	}
}

void BlockSet(int a) {
	static int i, j;
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			block[j][i] = blockForm[a][i][j];
		}
	}
	
}

void BlockPositionReset() {
	blockPosition_x = spawnPosition_x;
	blockPosition_y = spawnPosition_y;
}

