#include "DxLib.h"
#include "GV.h"
#include "Extern.h"


int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	
	extern void SetColor();
	extern void FpsTimeFanction();
	extern void FeeldSet();
	extern void DrawFeeld();
	extern void DrawBlock();
	extern void BlockSet(int a);
	extern void BlockPositionReset();
	extern int BlockRand();
	extern void BlockTurnRight(int a);
	extern void BlockTurnLeft(int a);
	extern void MoveLeft();
	extern void MoveRight();
	extern void MoveDrop();
	extern void BlockDelete();
	extern void GameOver();
	int RefreshTime = 0;

	playCounter = 0;

	spawnPosition_x = 4;
	spawnPosition_y = 0;

	ChangeWindowMode(TRUE);
	if (DxLib_Init() == -1) return -1;

	SetColor();

	FeeldSet();

	BlockPositionReset();

	SetDrawScreen(DX_SCREEN_BACK);                  //����ʂ��g�p����B

	nextBlockID = BlockRand();

	

	while (ProcessMessage() == 0 && GetHitKeyStateAll(Key) == 0) {
		RefreshTime = GetNowCount();               //���̎��Ԃ��擾
		ClearDrawScreen();  //����ʂ̃f�[�^��S�č폜

		DrawFeeld();

		if (CheckHitKey(KEY_INPUT_Z)==1)
			BlockTurnLeft(blockID);
		if (CheckHitKey(KEY_INPUT_X) == 1)
			BlockTurnRight(blockID);

		if (CheckHitKey(KEY_INPUT_LEFT)==1)
			MoveLeft();
		if (CheckHitKey(KEY_INPUT_RIGHT) == 1)
			MoveRight();
		if (CheckHitKey(KEY_INPUT_DOWN) == 1)
			MoveDrop();

		timeCounter++;
		if (timeCounter >= 60)
			MoveDrop();

		playCounter++;
		if (playCounter > 120) {
			blockID = nextBlockID;

			while (nextBlockID == blockID)
				nextBlockID = BlockRand();

			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					if (block[i][j] != 0)
						feeld[blockPosition_x + i][blockPosition_y + j] = block[i][j];
				}
			}

			BlockDelete();

			BlockPositionReset();

			BlockSet(blockID);

			GameOver();

			playCounter = 0;
		}

		DrawBlock();

		FpsTimeFanction();

		ScreenFlip();                             //����ʃf�[�^��\��ʂ֔��f

		if (Key[KEY_INPUT_ESCAPE] == 1)    break;     //Escape�������ꂽ��I��
		while (GetNowCount() - RefreshTime < 17);   //1���̏�����17�~���b�ɂȂ�܂ő҂�
	}

	DxLib_End();
	return 0;
}
