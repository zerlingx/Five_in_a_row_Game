#include "define.h"
#include<stack>


int chessBoard[GRID_NUM][GRID_NUM];//����

int countturns = 0;//��¼һ�»غ���

bool isinboard(int x, int y){//�Ƿ���������
	if (x >= 1 && x < GRID_NUM && y >= 1 && y < GRID_NUM) {
		return true;
	}
	else return false;
}

bool isblank(int x, int y) {//�Ƿ�λ��Ϊ��
	if (chessBoard[x][y] == blank) {
		return true;
	}
	else {
		return false;
	}
}

point ai, man;

general_situation generally_ai, generally_man;


int value[GRID_NUM][GRID_NUM];//ai��value
int antivalue[GRID_NUM][GRID_NUM];//man��value

int search_points;
int search_depth;

stack<point> createMoves(int player);