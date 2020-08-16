#include <iostream>
#include <queue>
#include <deque>
#define ROW 12
#define COL 6

using namespace std;

struct pos {
	int row;
	int col;
};
char map[ROW][COL] = { 0 };
pos dir[4] = { {0,1},{0,-1},{1,0},{-1,0} };

bool has_pop_puyo() {
	int visited[ROW][COL] = { 0 };
	int flag = false;
	vector<pos> pop_puyo_vec;

	for (int row = 0; row < ROW; row++) {
		for (int col = 0; col < COL; col++) {
			if (visited[row][col]) continue;
			else visited[row][col] = 1;

			if (map[row][col] == '.') continue;

			vector<pos> v;
			queue<pos> q;
			v.push_back({ row, col });
			q.push({ row, col });
			while (!q.empty()) {
				pos cur = q.front();
				q.pop();
				int color = map[row][col];
				for (int i = 0; i < 4; i++) {
					pos next = { cur.row + dir[i].row , cur.col + dir[i].col };
					if (next.row < 0 || next.row >= ROW) continue;
					if (next.col < 0 || next.col >= COL) continue;
					if (visited[next.row][next.col]) continue;
					if (map[next.row][next.col] == color) {
						v.push_back({ next.row, next.col });
						q.push({ next.row, next.col });
						visited[next.row][next.col] = 1;
					}
				}
			}

			if (v.size() >= 4) {
				flag = true;
				for (int i = 0; i < v.size(); i++)
					pop_puyo_vec.push_back(v[i]);
			}
		}
	}
	// 한꺼번에 map을 변경한다.
	for (auto pop_puyo : pop_puyo_vec)
		map[pop_puyo.row][pop_puyo.col] = '.';

	return flag;
}

void puyo_drop() {
	for (int col = 0; col < COL; col++) { // 열 단위로 떨어뜨림
		int row_top = ROW - 1;
		for (int row = ROW - 1; row >= 0; row--) {
			if (map[row][col] == '.') continue;
			if (row_top != row) {
				map[row_top][col] = map[row][col];
				map[row][col] = '.';
			}
			row_top--;
		}
	}
}


int main() {
	int answer = 0;
	for (int row = 0; row < ROW; row++) 
		for (int col = 0; col < COL; col++) 
			scanf(" %c", &map[row][col]);
	while (has_pop_puyo()) {
		puyo_drop();
		answer++;
	}
	cout << answer;
	return 0;
}
