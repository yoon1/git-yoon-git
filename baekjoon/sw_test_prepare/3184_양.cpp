#include <iostream>
#include <vector>
#include <queue>
#include <map>
#define MAX 250

using namespace std;

struct pos {
	int y, x;
};
int R, C;

char arr[MAX][MAX];
int sheep_num, wolf_num;
pos dir[4] = { {0,1},{0,-1},{1,0},{-1,0 } };
map <pair<int, int>, bool> wolf;

queue<pos> q;
bool isPossible(int y, int x) {
	if (y >= 0 && x >= 0 && y < R && x < C) return true;
	return false;
}
void bfs(int y, int x) {
	int cur_wolf_count = 1, cur_sheep_count = 0;
	arr[y][x] = '#';
	q.push({ y,x }); // 초기값 

	while (!q.empty()) {
		int cy = q.front().y;
		int cx = q.front().x;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = cy + dir[i].y;
			int nx = cx + dir[i].x;
			char &p = arr[ny][nx];
			if (!isPossible(ny,nx)) continue;
			if (p == '#') continue;
			if (p == 'v') {
				cur_wolf_count++;
				wolf[{ny, nx}] = true; // visited
			}
			if (p == 'o')
				cur_sheep_count++;
			p = '#'; // visited 체크
			q.push({ ny, nx });
		}
	}
	if (cur_sheep_count > cur_wolf_count)
		wolf_num -= cur_wolf_count;
	else
		sheep_num -= cur_sheep_count;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'v') {
				wolf[{i, j}] = false; // 늑대 false
				wolf_num++;
			}
			if (arr[i][j] == 'o') sheep_num++;
		}
	}
	int w_size = wolf.size();
	for (auto it = wolf.begin(); it != wolf.end(); it++) {
		if (it->second) continue; // 이미 방문한 늑대 X
		bfs(it->first.first, it->first.second);
	}
	cout << sheep_num << " " << wolf_num << endl;
	return 0;
}