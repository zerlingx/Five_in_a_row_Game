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

int alphabeta(int depth, int alpha, int beta, int player){//alghabeta剪枝
	//搜索主体

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
	if (depth == search_depth) return alpha + beta;//最终返回两种预期值之和
	return alpha;
}

void clear_stack(stack<point> a) {
	while (!a.empty()) {
		a.pop();
	}
	return;
}

void init_search_pattern() {//搜索模式修改
	search_points = 300;//搜索广度
	search_depth = 2;//搜索深度
	return;
}

point searchGoodmove(int player)			//得到招法，如果超时直接返回无效解。
{
	//这里是alphabeta的第一层
	if (countturns < 2) return evaluate(player);//开局直接用贪心解决

	point if_kill;
	if_kill = evaluate(player);
	if (generally_ai.max_value > 5000) return if_kill;//ai四连直接用贪心取胜
	if (generally_man.max_value > 5000) return if_kill;//man四连直接拦截

	int value_depart_available, value_depart_max = -1;

	
	int posibility_value_easy, posibility_value_deep;
	point posibility_move_easy, posibility_move_deep;

	search_depth = 2;
	search_points = 300;
	posibility_value_easy = alphabeta(search_depth, -inf, inf, player);//两层浅搜索
	posibility_move_easy = best_move;
	search_depth = 4;
	search_points = 20;
	posibility_value_deep = alphabeta(search_depth, -inf, inf, player);//四层深搜索
	posibility_move_deep = best_move;

	if (posibility_value_easy >= posibility_value_deep) return posibility_move_easy;
	else return posibility_move_deep;
}