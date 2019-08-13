#include "createmoves.h"
#include "define.h"
#include "evaluate.h"
#include "gameover.h"
#include "makemove.h"
#include "printchessboard.h"
#include "searchmove.h"
int main()
{
	memset(chessBoard, blank, sizeof(chessBoard));//��ʼ��
	init_chess_value();
	init_general_basic_value();
	init_search_pattern();
	countturns = 0;
	cout << "*************��ӭ�����������˻�����ϵͳ*************" << endl;
	cout << "����: white  ѡ����壨���֣�" << endl;
	cout << "����: black  ѡ����壨���֣�" << endl;
	cout << "����: m x y  ��ʾ���ӵ�" << endl;
	char input[64];

	int blackflag = 1;
	bool isaistrun = false;
	bool start = false;
manstrun:
	print();
	while (scanf("%s", input) != EOF)
	{
		system("cls");
		if (strcmp(input, "white") == 0 && start == false)//��������
		{
			isaistrun = true;
			countturns++;
			;
		}
		else if (strcmp(input, "black") == 0 && start == false)//���Ժ���
		{
			blackflag = 2;//man��black
			goto manstrun;
			;
		}
		else if (input[0] == 'm')//�������
		{
			cin >> man.x >> man.y;

			//�������
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

			//��Ч���壨man��
			if (blackflag == 1) {
				countturns++;//��man�����¼�غ�
				makeMove(man, white);
				if (gameover(white)) {//�վ��ж�
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

		if (isaistrun) {//ai����
			//��Ч���壨ai��
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
c���Ա���ԭ��
ͷ�ļ��÷�
#ifndef��#def��#endif�Ⱥ���÷�
http://www.51hei.com/bbs/dpj-54868-1.html
http://www.51hei.com/bbs/dpj-28952-1.html
http://www.51hei.com/bbs/dpj-46187-1.html

*/