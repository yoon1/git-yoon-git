#include <iostream>
#include <memory.h>
#include <deque>
#include <algorithm>
#include <vector>

using namespace std;


int map[20][20];
int visited[20][20];
int N;
typedef struct pos{
	int y;
	int x;
}Pos;
deque<pair<Pos, int>> q;
Pos dir[4] = { {-1,0}, {1,0 }, {0,-1}, {0,1} };
vector<pair<Pos,bool>> food[7];

int bfs(Pos target, int shark_lv) {
	pair<Pos, int> cur = q.front();
	while (!q.empty()) {
		cur = q.front();
		q.pop_front();
		if (cur.first.y == target.y && cur.first.x == target.x) {
			return cur.second;
		}
		for (int i = 0; i < 4; i++) {
			pair<Pos, int> next;
			next.first = { cur.first.y + dir[i].y , cur.first.x + dir[i].x };
			next.second = cur.second + 1;
			if (next.first.y >= 0 && next.first.y < N && next.first.x >= 0 && next.first.x < N){
				if ( visited[next.first.y][next.first.x] >= 0 && visited[next.first.y][next.first.x] <= shark_lv)
				{
					visited[next.first.y][next.first.x] = -1;
					q.push_back(next);
				}
			}
		}
	}
	return -1;
}

int main() {
	Pos shark_pos = { 0 , 0 };
	int shark_lv = 2;
	int shark_exp = 0;
	int shark_move = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] >= 1 && map[i][j] <= 6) {
				pair<Pos , bool> t = { Pos({ i, j }), true };
				food[map[i][j]].push_back(t);
			}
			else if (map[i][j] == 9) {
				map[i][j] = 0;
				shark_pos = Pos({i,j});
			}
		}
	}
	
	bool hasFood = true;

	while (hasFood) {
		hasFood = false;

		pair<Pos, int> move; // 이동 
		move.first = shark_pos; // shark의 위치
		move.second = 999999; // max값

		Pos food_pos = { 0,0 };
		for (int i = 1; i < shark_lv; i++) { // sahrk level : 첨엔 2 --> food는 1까지만 움직일수있음.
			for (int j = 0; j < food[i].size(); j++) { // 1인 거 찾아다님
				if (food[i][j].second) {
					q.clear(); // 일단 q초기화.
					memcpy(visited, map, sizeof(visited)); // visited 초기화.
					q.push_back(make_pair(shark_pos, 0)); // shark의 위치를 넣고 bfs돌릴거임.
					int move_t; // move_t값.
					move_t = bfs(food[i][j].first, shark_lv); // 거리값 반환.
					if ( move_t != -1 && 
						((move_t < move.second) // 새로 구한 값이 더 가까우면?
						|| (move_t == move.second && 
							((food[i][j].first.y < move.first.y)  // 값은 같은데 movefirst
							  || (food[i][j].first.y == move.first.y && food[i][j].first.x < move.first.x)))))
					{
						hasFood = true;
						food_pos = { i,j };
						move.first = food[i][j].first;
						move.second = move_t;				
					}
				}
			}
		}  
		if (hasFood) {
			if (move.second == 0 || move.second == 999999) {
				break;
			}
			map[move.first.y][move.first.x] = 0;
			shark_move += move.second;
			food[food_pos.y][food_pos.x].second = false;
			shark_exp++;
			shark_pos = move.first;
			if (shark_exp == shark_lv) {
				if (shark_lv <= 6) {
					shark_lv++;
					shark_exp = 0;
				}
			}
		}
	}
	cout << shark_move << endl;

	return 0;
}    