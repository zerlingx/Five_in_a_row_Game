
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

#define blank 0		//空白点
#define black 1		//黑方
#define white 2		//白方
//#define inboard(a,b) (a>0 && a<=15 && b>0 && b<=15)		//用于检验招法是否在棋盘上

#define GRID_NUM 16		
struct point {
	int x, y;//坐标
};

struct general_situation {
	int sum_of_scores;
	int max_value;
};


bool isinboard(int x, int y);
bool isblank(int x, int y);

//stack<point> createMoves(int player);


extern int chessBoard[GRID_NUM][GRID_NUM];//声明

extern int countturns;//回合数

extern point ai, man;

extern general_situation generally_ai, generally_man;


extern int value[GRID_NUM][GRID_NUM];//ai的value
extern int antivalue[GRID_NUM][GRID_NUM];//man的value
extern int general_basic_value;

extern int search_points;
extern int search_depth;


#endif

