#include "define.h"

void judge(int i, int j)
{
	if (i == 1 && j == 1)
		printf("  ");
	else if (i == 1 && j == 15)
		printf("  ");
	else if (i == 15 && j == 1)
		printf("  ");
	else if (i == 15 && j == 15)
		printf("  ");
	else if (i == 1 && j != 15 && j != 1)
		printf("——");
	else if (i == 15 && j != 15 && j != 1)
		printf("——");
	else if (j == 1 && i != 15 && i != 1)
		printf("| ");
	else if (j == 15 && i != 15 && i != 1)
		printf("| ");
	else
		printf(". ");
}

void print()
{
	for (int i = 0; i < 16; i++)
	{
		if (i == 0)
		{
			printf("  ");
			for (int j = 1; j < 16; j++)
				printf("%-2d",j);
			printf("\n");
			continue;
		}
		for (int j = 0; j < 16; j++)
		{
			if (j == 0)
			{
				printf("%2d", i);
				continue;
			}

			if (chessBoard[i][j] == 1)
				printf("○ ");
			else if (chessBoard[i][j] == 2)
				printf("● ");
			else
			{
				judge(i, j);
			}
		}

		if (i == 1) {
			printf("Turn:  %3d", countturns);
		}
		if (i == 2) {
			printf("AI:    (%2d,%2d)", ai.x, ai.y);
		}
		if (i == 3) {
			printf("Human: (%2d,%2d)", man.x, man.y);
		}
		if (i == 5) {
			printf("AI's winning rates:");
		}
		if (i == 6) {//永远算不对胜率的胜率计算
			printf("%05.2lf%%", (double)((double)generally_ai.sum_of_scores / ((double)generally_ai.sum_of_scores + (double)generally_man.sum_of_scores + (double)general_basic_value * 0.75)) * 100);
		}
		printf("\n");
	}
}
