#include "define.h"
#include "createmoves.h"
#include "makemove.h"
#include "evaluate.h"
#include <stack>
#include <stack>
# define inf 0x3f3f3f3f
using namespace std;
int antiplayer;
point best_move;


int valdiff(int player) {
	evaluate(player);
	return generally_ai.sum_of_scores - generally_man.sum_of_scores;
}

int alphabeta(int depth, int alpha, int beta, int player){//alghabeta��֦
	//��������

	if (depth == 0) {
		return valdiff(player);
	}

	stack<point> moves_available;
	point if_move;
	int val;
	moves_available = createMoves(player);
	while (!moves_available.empty()) {
		makeMove(moves_available.top(), player);
		val = -alphabeta(depth - 1, -beta, -alpha, player % 2 + 1);
		unMakeMove(moves_available.top(), player);
		if (val >= beta) {
			return beta;
		}
		if (val > alpha) {
			if(depth % 2 == 0) best_move = moves_available.top();
			alpha = val;
		}
		moves_available.pop();
	}
	if (depth == search_depth) return alpha + beta;//���շ�������Ԥ��ֵ֮��
	return alpha;
}

void clear_stack(stack<point> a) {
	while (!a.empty()) {
		a.pop();
	}
	return;
}

void init_search_pattern() {//����ģʽ�޸�
	search_points = 300;//�������
	search_depth = 2;//�������
	return;
}

point searchGoodmove(int player)			//�õ��з��������ʱֱ�ӷ�����Ч�⡣
{
	//������alphabeta�ĵ�һ��
	if (countturns < 2) return evaluate(player);//����ֱ����̰�Ľ��

	point if_kill;
	if_kill = evaluate(player);
	if (generally_ai.max_value > 5000) return if_kill;//ai����ֱ����̰��ȡʤ
	if (generally_man.max_value > 5000) return if_kill;//man����ֱ������

	int value_depart_available, value_depart_max = -1;

	
	int posibility_value_easy, posibility_value_deep;
	point posibility_move_easy, posibility_move_deep;

	search_depth = 2;
	search_points = 300;
	posibility_value_easy = alphabeta(search_depth, -inf, inf, player);//����ǳ����
	posibility_move_easy = best_move;
	search_depth = 4;
	search_points = 20;
	posibility_value_deep = alphabeta(search_depth, -inf, inf, player);//�Ĳ�������
	posibility_move_deep = best_move;

	if (posibility_value_easy >= posibility_value_deep) return posibility_move_easy;
	else return posibility_move_deep;
}