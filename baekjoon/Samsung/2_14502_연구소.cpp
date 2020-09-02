#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 8
using namespace std;

struct pos {
	int y, x;
};
int N, M;
int map[MAX][MAX]; // map
vector<pos> virus; // virus
pos dir[4] = { {0,1},{0,-1},{1,0},{-1,0} };
int answer = 0;

void bfs() {
	bool check[MAX][MAX];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			check[i][j] = false;
	queue <pos> q;
	for (pos vrs : virus)
		q.push(vrs); // virus 내보내기
	while (!q.empty()) {
		pos cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			pos next = { cur.y + dir[i].y, cur.x + dir[i].x };
			if (!(next.y >= 0 && next.x >= 0 && next.y < N && next.x < M)) continue;
			if (map[next.y][next.x] == 0 && !check[next.y][next.x]) {
				q.push(next);
				check[next.y][next.x] = true;
			}
		}
	}
	// count
	int cnt = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (map[i][j] == 0 && !check[i][j]) cnt++;
	answer = max(answer, cnt);
}
// wall
void dfs(int depth) {
	if (depth == 3) {
		bfs();
		return;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0) {
				map[i][j] = 1;
				dfs(depth + 1);
				map[i][j] = 0;
			}
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2)
				virus.push_back({ i,j }); // virus 위치
		}
	}
	dfs(0);
	cout << answer;
	return 0;
}