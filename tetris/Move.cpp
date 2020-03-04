#include "DxLib.h"
#include "Extern.h"

void MoveRight() {
	static int rightFlag = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (block[i][j] != 0)
				if (feeld[blockPosition_x + i + 1][blockPosition_y + j] == 0)
					rightFlag++;
				else
					goto loopend;
		}
	}
	if (rightFlag >= 4) {
		blockPosition_x++;
		playCounter = 0;
	}

loopend:
	if (0);
}

void MoveLeft() {
	static int leftFlag = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (block[i][j] != 0)
				if (feeld[blockPosition_x + i - 1][blockPosition_y + j] == 0)
					leftFlag++;
				else
					goto loopend;
		}
	}
	if (leftFlag >= 4) {
		blockPosition_x--;
		playCounter = 0;
	}

loopend:
	if (0);
}

void MoveDrop() {
	static int dropFlag = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (block[i][j] != 0)
				if (feeld[blockPosition_x + i][blockPosition_y + j + 1] == 0)
					dropFlag++;
				else {
					playCounter += 10;
					goto loopend;
				}
		}
	}
	if (dropFlag >= 4) {
		blockPosition_y++;
		playCounter = 0;
	}

loopend:
	timeCounter = 0;
}

void BlockTurnRight(int a) {

	static int i, j;

	blockRotate++;
	if (blockRotate >= 4)
		blockRotate = 0;

	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			if (blockForm[a][i][j + blockRotate * 4] != 0)
				if( feeld[blockPosition_x + i][blockPosition_y + j] != 0) {
					blockRotate--;
					if (blockRotate <= -1)
						blockRotate = 3;
					goto loopend;
				}
		}
	}
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			block[j][i] = blockForm[a][i][j + blockRotate * 4];
		}
	}
	playCounter = 0;
loopend:
	if (0);

}

void BlockTurnLeft(int a) {

	static int i, j;
	
	blockRotate--;
	if (blockRotate <= -1)
		blockRotate = 3;
	
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			if (blockForm[a][i][j + blockRotate * 4] != 0 
				&& feeld[blockPosition_x + i][blockPosition_y + j] != 0) {
				blockRotate++;
				if (blockRotate >= 4)
					blockRotate = 0;
				goto loopend;
			}
		}
	}
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			block[j][i] = blockForm[a][i][j + blockRotate * 4];
		}
	}
	playCounter = 0;
loopend:
	if (0); 

}