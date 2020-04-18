#include <cstdio>
#include <cstring>
#define MAX 500

using namespace std;

int map[MAX][MAX];
int visited[MAX][MAX];
int dirY[4] = { 0,1,0,-1 };
int dirX[4] = { 1,0,-1,0 };

int N, M;

bool isRange(int y, int x) {
	if (y >= 0 && y < N && x >= 0 && x < M) return true;
	return false;
}

int dfs(int y, int x) {
	if (y == N - 1 && x == M - 1)
		return 1;

	if (visited[y][x]) return visited[y][x];

	for (int i = 0; i < 4; i++) {
		int nextY = y + dirY[i];
		int nextX = x + dirX[i];
		if (isRange(nextY, nextX)) {
			if (map[nextY][nextX] < map[y][x]) {
				visited[y][x] += dfs(nextY, nextX);
			}
		}
	}
	return visited[y][x];
}

int main() {
	scanf_s("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf_s("%d", &map[i][j]);
		}
	}
	printf("%d", dfs(0, 0));
	return 0;
}