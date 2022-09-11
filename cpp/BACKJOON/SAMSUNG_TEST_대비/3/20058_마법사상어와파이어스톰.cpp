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
	// ȸ���� ����� temp[][]�� ����
	for (int i = 0; i < len; ++i) {
		for (int j = 0; j < len; ++j) {
			temp[j][len - 1 - i] = map[x + i][y + j];
		}
	}

	// ����� temp[][]�� ���� map[][]�� �ٽ� ����
	for (int i = 0; i < len; ++i) {
		for (int j = 0; j < len; ++j) {
			map[x + i][y + j] = temp[i][j];
		}
	}
}

void rotate() {
	// �κ� ���ں� ���� ��� ���� ��ġ�� ã���ϴ�.
	int len = 1 << L;
	for (int x = 0; x < N; x += len) {
		for (int y = 0; y < N; y += len) {
			// ���� ��ġ(x, y)�� �κа��� ũ�⸦ ���ڷ� ����
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
			// ������ ���� �߿��� ������ �ִ��� Ȯ��
			for (int i = 0; i < 4; ++i) {
				int nextX = x + dx[i];
				int nextY = y + dy[i];

				if (nextX < 0 || nextY < 0 || nextX >= N || nextY >= N) continue;
				if (map[nextX][nextY] <= 0) continue;
				cnt++;
			}
			// 3�� �̻� �����ϴ� ���
			if (cnt < 3) target[x][y] = 1;
		}
	}

	// ǥ�õ� ���� ���� �� ����
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
			// ������ ���� ���� ���� �κ� ����
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

			// ������ ����ų� �̹� �湮(ǥ��)�� ��, ������ �ƴ� ���� ����
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
			// �̹� ǥ�õǾ� �ְų� ������ �ƴ� ���� ����
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
		// �κ� ���ں� ȸ��
		rotate();
		// ���� ���̱�
		meltIce();
	}

	// ���� �ִ� ������ ��
	printf("%d\n", sumIce());
	// ���� ū ������ ���� ����(����)
	printf("%d\n", findLargePiece());
}