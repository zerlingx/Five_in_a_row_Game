#include "define.h"

bool gameover(int player)//����Ƿ���Ϸ����
{
	//�ж���Ϸ�Ƿ����
	int i, j, line, times;

	//������
	for (i = 1; i <= GRID_NUM; i++) {
		for (j = 1; j <= GRID_NUM - 4; j++) {
			if (chessBoard[i][j] == player && chessBoard[i][j + 1] == player && chessBoard[i][j + 2] == player && chessBoard[i][j + 3] == player && chessBoard[i][j + 4] == player) {
				return true;
			}
		}
	}

	//������
	for (i = 1; i <= GRID_NUM - 4; i++) {
		for (j = 1; j <= GRID_NUM; j++) {
			if (chessBoard[i][j] == player && chessBoard[i + 1][j] == player && chessBoard[i + 2][j] == player && chessBoard[i + 3][j] == player && chessBoard[i + 4][j] == player) {
				return true;
			}
		}
	}

	//������������б
	for (i = 1; i <= GRID_NUM - 4; i++) {
		for (j = 1; j <= GRID_NUM - 4; j++) {
			if (chessBoard[i][j] == player && chessBoard[i + 1][j + 1] == player && chessBoard[i + 2][j + 2] == player && chessBoard[i + 3][j + 3] == player && chessBoard[i + 4][j + 4] == player) {
				return true;
			}
		}
	}

	//������������б
	for (i = 1; i <= GRID_NUM - 4; i++) {
		for (j = 5; j <= GRID_NUM; j++) {
			if (chessBoard[i][j] == player && chessBoard[i + 1][j - 1] == player && chessBoard[i + 2][j - 2] == player && chessBoard[i + 3][j - 3] == player && chessBoard[i + 4][j - 4] == player) {
				return true;
			}
		}
	}

	return false;
}

/*

	for (i = 1; i <= GRID_NUM; i++) {
		for (j = 1; j <= GRID_NUM; j++) {
			if (chessBoard[i][j] == player && chessBoard[i][j] == player && chessBoard[i][j] == player && chessBoard[i][j] == player && chessBoard[i][j] == player) {

			}
		}
	}

*/