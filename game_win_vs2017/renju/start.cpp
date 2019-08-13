#include "createmoves.h"
#include "define.h"
#include "evaluate.h"
#include "gameover.h"
#include "makemove.h"
#include "printchessboard.h"
#include "searchmove.h"
int main()
{
	memset(chessBoard, blank, sizeof(chessBoard));//初始化
	init_chess_value();
	init_general_basic_value();
	init_search_pattern();
	countturns = 0;
	cout << "*************欢迎来到五子棋人机对弈系统*************" << endl;
	cout << "输入: white  选择白棋（后手）" << endl;
	cout << "输入: black  选择黑棋（先手）" << endl;
	cout << "输入: m x y  表示落子点" << endl;
	char input[64];

	int blackflag = 1;
	bool isaistrun = false;
	bool start = false;
manstrun:
	print();
	while (scanf("%s", input) != EOF)
	{
		system("cls");
		if (strcmp(input, "white") == 0 && start == false)//电脑先手
		{
			isaistrun = true;
			countturns++;
			;
		}
		else if (strcmp(input, "black") == 0 && start == false)//电脑后手
		{
			blackflag = 2;//man是black
			goto manstrun;
			;
		}
		else if (input[0] == 'm')//玩家落子
		{
			cin >> man.x >> man.y;

			//下棋错误
			if (!isinboard(man.x, man.y)) {
				printf("         Out of board!!!\n");
				print();
				continue;
			}
			if (!isblank(man.x, man.y)) {
				printf("        Can't set here!!!\n");
				print();
				continue;
			}

			//有效下棋（man）
			if (blackflag == 1) {
				countturns++;//以man下棋记录回合
				makeMove(man, white);
				if (gameover(white)) {//终局判断
					system("cls");
					printf("\n\n        White win !  (^ - ^)/\n");
					print();
					system("pause");
					return 0;
				}
			}
			else {
				countturns++;
				makeMove(man, black);
				if (gameover(black)) {
					system("cls");
					printf("\n\n        Black win !  (^ - ^)/\n");
					print();
					system("pause");
					return 0;
				}
			}
			system("cls");
			print();
			isaistrun = true;
			start = true;
			;

		}
		else
		{
			printf("        Input error!!!\n");
			print();
			;
		}

		if (isaistrun) {//ai下棋
			//有效下棋（ai）
			if (blackflag == 1) {
				//ai = evaluate(black);
				ai = searchGoodmove(black);
				makeMove(ai, black);
				if (gameover(black)) {
					system("cls");
					printf("\n\n        Black win !  (^ - ^)/\n");
					print();
					system("pause");
					return 0;
				}
			}
			else {
				//ai = evaluate(white);
				ai = searchGoodmove(white);
				makeMove(ai, white);
				if (gameover(white)) {
					system("cls");
					printf("\n\n        White win !  (^ - ^)/\n");
					print();
					system("pause");
					return 0;
				}
			}
			system("cls");
			print();
			isaistrun = false;
			start = true;
		}
	}
}





/*
c语言编译原理
头文件用法
#ifndef、#def、#endif等宏的用法
http://www.51hei.com/bbs/dpj-54868-1.html
http://www.51hei.com/bbs/dpj-28952-1.html
http://www.51hei.com/bbs/dpj-46187-1.html

*/