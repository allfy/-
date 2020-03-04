#include "DxLib.h"
#include "Extern.h"
#include <ctime>        // time
#include <cstdlib>      // srand,rand

extern void DrawBlock();

int BlockRand() {
	srand(time(NULL));
	return rand() % 7;
}

void BlockDelete() {
	int deleteFlag = 21;
	for (int i = 1; i < 21; i++) {
		for (int j = 1; j < 11; j++) {
			if (feeld[j][i] == 0) {
				deleteFlag = 21;
				break;
			}
			else {
				deleteFlag = i;
			}
		}
		if (deleteFlag < 21) {
			for (int l = deleteFlag; l > 0; l--) {
				for (int k = 1; k < 11; k++) {
					feeld[k][l] = feeld[k][l - 1];
				}
			}
		}
	}
}

void GameOver() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if(block[i][j]!=0)
				if (feeld[spawnPosition_x + i][spawnPosition_y + j] != 0) {
					DrawFormatString(60, 210, color_white, "GAME OVER" );
					DrawBlock();
					ScreenFlip();
					while (1) {
						if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)
							break;
					}

				}
		}
	}
}