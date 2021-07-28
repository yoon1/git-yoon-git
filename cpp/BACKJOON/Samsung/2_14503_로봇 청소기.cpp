#include <iostream>
#define MAX 50

using namespace std;

int N, M; 
int map[MAX][MAX];
int dutyZone;
int answer;

pair<int, int> dir[4] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} }; // 북, 동, 남, 서

bool isPossible(int y, int x) {
	if (y >= 0 && y < N && x >= 0 && x < M) return true;
	return false;
}
void dfs(int y, int x, int d) {// 좌표, 방향
	if (answer == dutyZone)
		return;
	
	for (int i = 3; i >= 0; i--) {
		int nd = (d + i) % 4;
		int ny = y + dir[nd].first;
		int nx = x + dir[nd].second;
		if (!isPossible(ny, nx)) continue;
		if (map[ny][nx] == 0) {
			map[ny][nx] = 2;
			answer++;
			dfs(ny, nx, nd);
			return; // 끝나면은 return
		}
	}
	int preY = y - dir[d].first;
	int preX = x - dir[d].second;
	if (isPossible(preY, preX)) {
		if (map[preY][preX] == 2)
			dfs(preY, preX, d);
	}
}

int main() {
	int r, c, d;
	cin >> N >> M >> r >> c >> d;

	for (int i = 0; i < N; i++) 
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0) dutyZone++;
		}
	map[r][c] = 2;
	answer = 1;
	dfs(r,c,d);
	cout << answer << endl;
}