#include "define.h"
int pre[GRID_NUM][GRID_NUM];
void makeMove(struct point node, int color)
{
	//落子
	if (!isinboard(node.x, node.y)) {
		printf("\n         Out of board!!!\n\n");
		return;
	}
	if (!isblank(node.x, node.y)) {
		printf("\n        Can't set here!!!\n\n");
		return;
	}
	pre[node.x][node.y] = chessBoard[node.x][node.y];//备份一下
	chessBoard[node.x][node.y] = color;//把点打印上去
	
}

void unMakeMove(struct point node, int color)
{
	//撤销落子
	chessBoard[node.x][node.y] = pre[node.x][node.y];

}