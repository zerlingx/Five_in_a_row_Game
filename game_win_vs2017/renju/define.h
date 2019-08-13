
#ifndef _DEFINE_
#define _DEFINE_

#include <stdio.h>
#include <string.h>
#include <string>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <stack>
using namespace std;

#define blank 0		//�հ׵�
#define black 1		//�ڷ�
#define white 2		//�׷�
//#define inboard(a,b) (a>0 && a<=15 && b>0 && b<=15)		//���ڼ����з��Ƿ���������

#define GRID_NUM 16		
struct point {
	int x, y;//����
};

struct general_situation {
	int sum_of_scores;
	int max_value;
};


bool isinboard(int x, int y);
bool isblank(int x, int y);

//stack<point> createMoves(int player);


extern int chessBoard[GRID_NUM][GRID_NUM];//����

extern int countturns;//�غ���

extern point ai, man;

extern general_situation generally_ai, generally_man;


extern int value[GRID_NUM][GRID_NUM];//ai��value
extern int antivalue[GRID_NUM][GRID_NUM];//man��value
extern int general_basic_value;

extern int search_points;
extern int search_depth;


#endif

