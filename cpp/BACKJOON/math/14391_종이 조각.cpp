#include <iostream>
#define MAX 4
#define RIGHT 0
#define DOWN 1
using namespace std;

int N, M;
int map[MAX][MAX];
bool visited[MAX*MAX];
int dy[2] = {0,1};
int dx[2] = {1,0};

void solution() {
	// 조각의 합 찾기
	for (int i = 0; i < 16; i++) {
		visited[i][j]
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			scanf("%1d", &map[i][j]);

	solution();
	return 0;
}