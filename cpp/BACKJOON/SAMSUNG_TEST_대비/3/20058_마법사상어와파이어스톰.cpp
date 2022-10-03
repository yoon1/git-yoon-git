#include <stdio.h>
#include <queue>
using namespace std;
inline int max(int A, int B) { return A > B ? A : B; }
const int MAX_N = (1 << 6) + 5;
const int dx[] = { 0, 0, -1, 1 };
const int dy[] = { -1, 1,  0, 0 };
int N, Q, L;
int map[MAX_N][MAX_N], visited[MAX_N][MAX_N];
int target[MAX_N][MAX_N], temp[MAX_N][MAX_N];
struct Node {
	int x, y;
};
queue<Node> que;

void rotate(int x, int y, int len) {
	// 회전한 모양을 temp[][]에 저장
	for (int i = 0; i < len; ++i) {
		for (int j = 0; j < len; ++j) {
			temp[j][len - 1 - i] = map[x + i][y + j];
		}
	}

	// 저장된 temp[][]의 값을 map[][]에 다시 저장
	for (int i = 0; i < len; ++i) {
		for (int j = 0; j < len; ++j) {
			map[x + i][y + j] = temp[i][j];
		}
	}
}

void rotate() {
	// 부분 격자별 좌측 상단 시작 위치를 찾습니다.
	int len = 1 << L;
	for (int x = 0; x < N; x += len) {
		for (int y = 0; y < N; y += len) {
			// 시작 위치(x, y)와 부분격자 크기를 인자로 전달
			rotate(x, y, len);
		}
	}
}

void meltIce() {
	for (int x = 0; x < N; ++x) {
		for (int y = 0; y < N; ++y) {
			target[x][y] = 0;
		}
	}

	for (int x = 0; x < N; ++x) {
		for (int y = 0; y < N; ++y) {
			int cnt = 0;
			// 인접한 방향 중에서 얼음이 있는지 확인
			for (int i = 0; i < 4; ++i) {
				int nextX = x + dx[i];
				int nextY = y + dy[i];

				if (nextX < 0 || nextY < 0 || nextX >= N || nextY >= N) continue;
				if (map[nextX][nextY] <= 0) continue;
				cnt++;
			}
			// 3곳 이상 존재하는 경우
			if (cnt < 3) target[x][y] = 1;
		}
	}

	// 표시된 곳의 얼음 양 감소
	for (int x = 0; x < N; ++x) {
		for (int y = 0; y < N; ++y) {
			if (target[x][y]) map[x][y]--;
		}
	}
}

int sumIce() {
	int ret = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			// 얼음이 남아 있지 않은 부분 제외
			if (map[i][j] <= 0) continue;
			ret += map[i][j];
		}
	}
	return ret;
}

int BFS(int x, int y) {
	int ret = 1;
	que.push({ x ,y });
	visited[x][y] = 1;
	while (!que.empty()) {
		Node cur = que.front(); que.pop();
		for (int i = 0; i < 4; ++i) {
			int nextX = cur.x + dx[i];
			int nextY = cur.y + dy[i];

			// 범위를 벗어나거나 이미 방문(표시)한 곳, 얼음이 아닌 곳은 제외
			if (nextX < 0 || nextY < 0 || nextX >= N || nextY >= N) continue;
			if (visited[nextX][nextY] || map[nextX][nextY] <= 0) continue;

			ret++;
			visited[nextX][nextY] = 1;
			que.push({ nextX, nextY });
		}
	}
	return ret;
}

int findLargePiece() {
	int largePiece = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			// 이미 표시되어 있거나 얼음이 아닌 곳은 제외
			if (visited[i][j] || map[i][j] <= 0) continue;
			largePiece = max(largePiece, BFS(i, j));
		}
	}
	return largePiece;
}

int main() {
	// freopen("input.txt", "r", stdin);
	scanf("%d %d", &N, &Q);
	N = 1 << N;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			scanf("%d", &map[i][j]);
		}
	}

	for (int i = 0; i < Q; ++i) {
		scanf("%d", &L);
		// 부분 격자별 회전
		rotate();
		// 얼음 녹이기
		meltIce();
	}

	// 남아 있는 얼음의 양
	printf("%d\n", sumIce());
	// 가장 큰 조각의 얼음 공간(개수)
	printf("%d\n", findLargePiece());
}