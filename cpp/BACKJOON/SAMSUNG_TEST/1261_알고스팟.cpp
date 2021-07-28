#include <iostream>
#include <tuple>
#include <limits.h>
#include <queue>

#define MAX 100

using namespace std;

struct pos {
	int y; 
	int x;
};
int map[MAX][MAX];
bool visited[MAX][MAX];
int N, M;
pos dir[4] = { {0,1},{0,-1},{1,0},{-1,0} };

int bfs() {
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
	q.push({ 0,{0,0 } }); // start
	visited[0][0] = true;
	while (!q.empty()) {
		pair<int, pair<int, int>> t = q.top();
		pos cur = {t.second.first , t.second.second}; // y, x
		int crush = t.first;
		q.pop();
		if (cur.y == N - 1 && cur.x == M - 1) 
			return crush;
		for (int i = 0; i < 4; i++) {
			pos next = { cur.y + dir[i].y, cur.x + dir[i].x };
			if (!(next.y >= 0 && next.x >= 0 && next.y < N && next.x < M)) continue;
			if (visited[next.y][next.x]) continue;
			visited[next.y][next.x] = true;
			int next_crush = map[next.y][next.x] ? 1 : 0;
			q.push({ crush + next_crush ,{ next.y, next.x} });
		}
	}
}
int main() {
	cin >> M >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			scanf("%1d", &map[i][j]);
	cout << bfs()<< endl;
	return 0;
}

