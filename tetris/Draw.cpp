#include "DxLib.h"
#include "Extern.h"

void DrawFeeld() {
	static int i, j;
	for (i = 0; i < 12; i++) {
		for (j = 0; j < 22; j++) {
			if (feeld[i][j] == 1)
				DrawBox(i*20, j*20, i*20+18, j*20+18,
					color_yellow, TRUE);
			else if (feeld[i][j] == 2)
				DrawBox(i * 20, j * 20, i * 20 + 18, j * 20 + 18,
					color_fuchsia, TRUE);
			else if (feeld[i][j] == 3)
				DrawBox(i * 20, j * 20, i * 20 + 18, j * 20 + 18,
					color_orange, TRUE);
			else if (feeld[i][j] == 4)
				DrawBox(i * 20, j * 20, i * 20 + 18, j * 20 + 18,
					color_blue, TRUE);
			else if (feeld[i][j] == 5)
				DrawBox(i * 20, j * 20, i * 20 + 18, j * 20 + 18,
					color_green, TRUE);
			else if (feeld[i][j] == 6)
				DrawBox(i * 20, j * 20, i * 20 + 18, j * 20 + 18,
					color_red, TRUE);
			else if (feeld[i][j] == 7)
				DrawBox(i * 20, j * 20, i * 20 + 18, j * 20 + 18,
					color_aqua, TRUE);
			else if (feeld[i][j] == 9)
				DrawBox(i * 20, j * 20, i * 20 + 18, j * 20 + 18,
					color_white, TRUE);

		}
	}
}

void DrawBlock() {
	static int i, j;
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			if (block[i][j] == 1)
				DrawBox((blockPosition_x + i) * 20, (blockPosition_y + j) * 20,
					(blockPosition_x + i) * 20 + 18, (blockPosition_y + j) * 20 + 18,
					color_yellow, TRUE);
			else if (block[i][j] == 2)
				DrawBox((blockPosition_x + i) * 20, (blockPosition_y + j) * 20,
					(blockPosition_x + i) * 20 + 18, (blockPosition_y + j) * 20 + 18,
					color_fuchsia, TRUE);
			else if (block[i][j] == 3)
				DrawBox((blockPosition_x + i) * 20, (blockPosition_y + j) * 20,
					(blockPosition_x + i) * 20 + 18, (blockPosition_y + j) * 20 + 18,
					color_orange, TRUE);
			else if (block[i][j] == 4)
				DrawBox((blockPosition_x + i) * 20, (blockPosition_y + j) * 20,
					(blockPosition_x + i) * 20 + 18, (blockPosition_y + j) * 20 + 18,
					color_blue, TRUE);
			else if (block[i][j] == 5)
				DrawBox((blockPosition_x + i) * 20, (blockPosition_y + j) * 20,
					(blockPosition_x + i) * 20 + 18, (blockPosition_y + j) * 20 + 18,
					color_green, TRUE);
			else if (block[i][j] == 6)
				DrawBox((blockPosition_x + i) * 20, (blockPosition_y + j) * 20,
					(blockPosition_x + i) * 20 + 18, (blockPosition_y + j) * 20 + 18,
					color_red, TRUE);
			else if (block[i][j] == 7)
				DrawBox((blockPosition_x + i) * 20, (blockPosition_y + j) * 20,
					(blockPosition_x + i) * 20 + 18, (blockPosition_y + j) * 20 + 18,
					color_aqua, TRUE);
		}
	}
}