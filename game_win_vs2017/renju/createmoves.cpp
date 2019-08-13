#include "define.h"
#include "evaluate.h"
#include "searchmove.h"
#include <stack>
#include <vector>
#include <algorithm>

struct better_points {
	point the_point;
	int the_value;
};

vector<better_points> tops;
stack<point> top_moves;

better_points read_move_and_sort;
point read_move;

bool cmp(better_points a, better_points b) {
	return a.the_value > b.the_value;
}

stack<point> createMoves(int player)		//�����з�
{
	//�����з�����
	//�����ϵĿհ׵��Ϊ�����з�
	
	int i, j;
	while (!top_moves.empty()) {
		top_moves.pop();
	}

	for(i = 1 ; i < GRID_NUM ; i++)
		for (j = 1; j < GRID_NUM; j++) {
			if (isblank(i, j)) {
				read_move_and_sort.the_point.x = i;
				read_move_and_sort.the_point.y = j;
				read_move_and_sort.the_value = value[i][j] + antivalue[i][j];
				tops.push_back(read_move_and_sort);
			}
		}


	sort(tops.begin(), tops.end(), cmp);
	int use_tops = search_points;//���������ĵ������
	while (!tops.empty() && use_tops > 0) {
		top_moves.push(tops.front().the_point);
		tops.erase(tops.begin());
		use_tops--;
	}
	tops.clear();



	return top_moves;
}