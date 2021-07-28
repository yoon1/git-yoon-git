#include <iostream>
#include <queue>
#define MAX 250

using namespace std;

int N, M;
char map[MAX][MAX] = { 0 };
bool visited[MAX][MAX] = { false };
struct pos {
	int y, x;
};
int dy[4] = { 0,0,-1,1 };
int dx[4] = { -1,1,0,0 };

pair<int, int> bfs(int sy, int sx) {
	queue<pos> q;
	q.push({ sy, sx });
	visited[sy][sx] = true;
	int sheep = 0, wolf = 0;

	while(!q.empty()) {
		pos cur = q.front();
		q.pop();
		switch (map[cur.y][cur.x]) {
			case 'v': wolf++; break;
			case 'k': sheep++; break;
			default: break;
		}
		for (int i = 0; i < 4; i++) {
			int ny = cur.y + dy[i];
			int nx = cur.x + dx[i];
			if (!(ny >= 0 && ny < N && nx >= 0 && nx < M)) continue;
			if (visited[ny][nx]) continue;
			if (map[ny][nx] == '#') continue;
			visited[ny][nx] = true;
			q.push({ ny, nx });
			
		}
	}
	if (sheep > wolf) return {sheep, 0};
	else return { 0, wolf };
}

int main() {
	int total_sheep = 0, total_wolf = 0;
	scanf("%d %d\n", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%c", &map[i][j]);
		}
		char space; scanf("%c", &space);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!visited[i][j]) {
				pair<int, int> t = bfs(i,j);
				total_sheep += t.first;
				total_wolf += t.second;
			}
		}
	}

	cout << total_sheep << " " << total_wolf;
	return 0;
}