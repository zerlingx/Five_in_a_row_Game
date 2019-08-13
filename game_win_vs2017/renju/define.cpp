#include "define.h"
#include<stack>


int chessBoard[GRID_NUM][GRID_NUM];//定义

int countturns = 0;//记录一下回合数

bool isinboard(int x, int y){//是否在棋盘内
	if (x >= 1 && x < GRID_NUM && y >= 1 && y < GRID_NUM) {
		return true;
	}
	else return false;
}

bool isblank(int x, int y) {//是否位置为空
	if (chessBoard[x][y] == blank) {
		return true;
	}
	else {
		return false;
	}
}

point ai, man;

general_situation generally_ai, generally_man;


int value[GRID_NUM][GRID_NUM];//ai的value
int antivalue[GRID_NUM][GRID_NUM];//man的value

int search_points;
int search_depth;

stack<point> createMoves(int player);