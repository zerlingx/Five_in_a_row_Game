#include "define.h"
#include<cstring>

//������ֵ�ֲ�
int basic_value[GRID_NUM][GRID_NUM] =//������ֵ
{//  0  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15
	{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},//0
	{-1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},//1
	{-1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1},//2
	{-1, 1, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2, 1},//3
	{-1, 1, 2, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 3, 2, 1},//4
	{-1, 1, 2, 3, 4, 5, 5, 5, 5, 5, 5, 5, 4, 3, 2, 1},//5
	{-1, 1, 2, 3, 4, 5, 6, 6, 6, 6, 6, 5, 4, 3, 2, 1},//6
	{-1, 1, 2, 3, 4, 5, 6, 7, 7, 7, 6, 5, 4, 3, 2, 1},//7
	{-1, 1, 2, 3, 4, 5, 6, 7, 8, 7, 6, 5, 4, 3, 2, 1},//8
	{-1, 1, 2, 3, 4, 5, 6, 7, 7, 7, 6, 5, 4, 3, 2, 1},//9
	{-1, 1, 2, 3, 4, 5, 6, 6, 6, 6, 6, 5, 4, 3, 2, 1},//10
	{-1, 1, 2, 3, 4, 5, 5, 5, 5, 5, 5, 5, 4, 3, 2, 1},//11
	{-1, 1, 2, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 3, 2, 1},//12
	{-1, 1, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2, 1},//13
	{-1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1},//14
	{-1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},//15
};
int general_basic_value;
void init_general_basic_value() {
	int i, j;
	general_basic_value = 0;
	for(i = 1 ; i < GRID_NUM ; i++)
		for (j = 1; j < GRID_NUM; j++) {
			general_basic_value += basic_value[i][j];
		}
}

void init_chess_value() {//��ʼ��
	memset(value, 0, sizeof(value));
	memset(antivalue, 0, sizeof(antivalue));
	return;
}


int i, j, maxvalue_ai, maxvalue_man;
//�������ҵ������ؼ�ֵ���ĵ�
point find_the_most_value(int color) {
	maxvalue_ai = -1;
	maxvalue_man = -1;

	generally_ai.sum_of_scores = 0;//��ʼ����ͳ��ai��man��������ֺ���߹��ֵ�
	generally_ai.max_value = -1;
	generally_man.sum_of_scores = 0;
	generally_man.max_value = -1;

	point most_value_point_as_ai;//����ai�ܵõ����������ĵ�
	for (i = 1; i < GRID_NUM; i++) {
		for (j = 1; j < GRID_NUM; j++) {

			generally_ai.sum_of_scores += value[i][j];

			if (basic_value[i][j] + value[i][j] >= maxvalue_ai && isblank(i, j) && isinboard(i, j)) {//��ֵ���ĵ�
				maxvalue_ai = basic_value[i][j] + value[i][j];

				generally_ai.max_value = maxvalue_ai;

				most_value_point_as_ai.x = i;//ͼ�ϱ����1-15
				most_value_point_as_ai.y = j;
			}
		}
	}

	point most_value_point_as_man;//����man�ܵõ����������ĵ�
	for (i = 1; i < GRID_NUM; i++) {
		for (j = 1; j < GRID_NUM; j++) {

			generally_man.sum_of_scores += antivalue[i][j];

			if (basic_value[i][j] + antivalue[i][j] >= maxvalue_man && isblank(i, j) && isinboard(i, j)) {//��ֵ���ĵ�
				maxvalue_man = basic_value[i][j] + antivalue[i][j];

				generally_man.max_value = maxvalue_man;

				most_value_point_as_man.x = i;//ͼ�ϱ����1-15
				most_value_point_as_man.y = j;
			}
		}
	}

	if (maxvalue_ai >= maxvalue_man + 2) {//�����������������Χ��
		return most_value_point_as_ai;
	}
	else {
		return most_value_point_as_man;
	}

}



/*
//�浵һ��������ٻ���ͦ���õĴ�̰�ļ���
point find_the_most_value(int color) {
	maxvalue = -1;
	point most_value_point;
	for (i = 1; i < GRID_NUM; i++) {
		for (j = 1; j < GRID_NUM; j++) {
			if (basic_value[i][j] + value[i][j] + antivalue[i][j] >= maxvalue && isblank(i, j) && isinboard(i, j)) {//��ֵ���ĵ�
				maxvalue = basic_value[i][j] + value[i][j] + antivalue[i][j];
				most_value_point.x = i;//ͼ�ϱ����1-15
				most_value_point.y = j;
			}
		}
	}
	return most_value_point;
}
*/









int moveto[9][2] = {//�ƶ�����[k][0]->x,[k][1]->y
	{0 ,0},//0
	{-1,-1},{-1, 0},{-1, 1},//1,2,3
	{0 , 1},//4
	{0 ,-1},//5
	{1 ,-1},{1 , 0},{1 , 1}//6,7,8
};

struct situation {//�ж����ӵ����������find()
	int line, empty;
};
situation inevaluate;
situation infind;
point findnext;
situation find(int x, int y, int direction, int color) {//���ض�����Ѱ�ң��жϸ����ӵ����
	/*  direction:
	1 2 3
	5 0 4
	6 7 8
	*///�Խ���ӵ���9�������жϷ�����

	x += moveto[direction][0];
	y += moveto[direction][1];
	if (!isinboard(x, y)) return infind;
	if (chessBoard[x][y] == color) {//����
		infind.line++;
		if (infind.line >= 5) return infind;
		return find(x, y, direction, color);
	}
	else if (isblank(x, y)) {//�հ�
		infind.empty++;
	}
	else {//���
		;
	}
	return infind;
}


//����������ؼ�ֵ
int its_value[6][3]; //itsvalue[line][empty] = value
void init_its_value() {
	memset(its_value, 0, sizeof(its_value));
	its_value[1][1] = 1;
	its_value[1][2] = 2;
	its_value[2][1] = 10;
	its_value[2][2] = 15;
	its_value[3][1] = 100;
	its_value[3][2] = 300;
	its_value[4][1] = 10000;
	its_value[4][2] = 20000;
	its_value[5][1] = 500000;
	its_value[5][2] = 500100;
	return;
}

point evaluate(int color)//��ֵ�㷨���õ�value��antivalue��ֵ����ai�������ĵ�
{
	int anticolor = color % 2 + 1;//color�ǵ�����ɫ��anticolor��������ɫ
	point mov;
	//ͳ�����ͽ��й�ֵ

	int tx, ty, i, j, k, direction, direct_point_value;
	init_chess_value();//��ʼ��value��antivalue
	init_its_value();//��ʼ����ֵ��

	for (i = 1; i < GRID_NUM; i++)//����chessBoard�����е�,��value��antivalueȫ�ֹ�ֵ
	{
		for (j = 1; j < GRID_NUM; j++)
		{
			if (isblank(i, j)) {//�õ�հ�
				for (k = 1; k <= 8; k++) {//������Χ��û������
					tx = i + moveto[k][0];
					ty = j + moveto[k][1];
					if (!isinboard(tx, ty)) continue;

					//�����Χ�������������
					if (chessBoard[tx][ty] == color) {//ai����
						//�����������k������ҿ���û��������
						infind.line = 1;
						infind.empty = 0;
						findnext.x = tx + moveto[9 - k][0];//�����Ƿ�blank
						findnext.y = ty + moveto[9 - k][1];
						if (isblank(findnext.x, findnext.y)) infind.empty++;

						inevaluate = find(tx, ty, k, color);//��direction������,�õ����ӵ��������
						direct_point_value = its_value[inevaluate.line][inevaluate.empty];
						if (direct_point_value >= value[i][j]) value[i][j] = direct_point_value;
					}


					if (chessBoard[tx][ty] == anticolor) {//man����
						infind.line = 1;
						infind.empty = 0;
						findnext.x = tx + moveto[9 - k][0];
						findnext.y = ty + moveto[9 - k][1];
						if (isblank(findnext.x, findnext.y)) infind.empty++;

						inevaluate = find(tx, ty, k, anticolor);
						direct_point_value = its_value[inevaluate.line][inevaluate.empty] + 0;//����Χ�¾ͼ����ض�ֵ
						if (direct_point_value >= antivalue[i][j]) antivalue[i][j] = direct_point_value;
					}
				}
			}
		}
	}




	//�������ĵ�
	mov = find_the_most_value(color);

	return  mov;
}