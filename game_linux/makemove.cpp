#include "define.h"
int pre[GRID_NUM][GRID_NUM];
void makeMove(struct point node, int color)
{
	//����
	if (!isinboard(node.x, node.y)) {
		printf("\n         Out of board!!!\n\n");
		return;
	}
	if (!isblank(node.x, node.y)) {
		printf("\n        Can't set here!!!\n\n");
		return;
	}
	pre[node.x][node.y] = chessBoard[node.x][node.y];//����һ��
	chessBoard[node.x][node.y] = color;//�ѵ��ӡ��ȥ
	
}

void unMakeMove(struct point node, int color)
{
	//��������
	chessBoard[node.x][node.y] = pre[node.x][node.y];

}