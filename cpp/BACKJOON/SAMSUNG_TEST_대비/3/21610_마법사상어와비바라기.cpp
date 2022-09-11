#include <iostream>
#include <vector>
using namespace std;
const int MAX_N = 50;
const int dx[] = { 0, 0, -1, -1, -1, 0, 1, 1, 1 };
const int dy[] = { 0, -1, -1, 0, 1, 1, 1, 0, -1 };
struct Node {
	int x, y;
};

int N, M, d, s;
int map[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
vector<Node> clouds;

void input()
{
	// map 크기(N), 이동 명령 횟수(M)
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	// 초기 구름
	clouds.push_back({ N - 1, 0 });
	clouds.push_back({ N - 1, 1 });
	clouds.push_back({ N - 2, 0 });
	clouds.push_back({ N - 2, 1 });
}

void moveClouds(int d, int s) {
	s = s % N;
	for (int c = 0; c < clouds.size(); ++c)
	{
		clouds[c].x = (clouds[c].x + s * dx[d] + N) % N;
		clouds[c].y = (clouds[c].y + s * dy[d] + N) % N;
		map[clouds[c].x][clouds[c].y]++; // 바구니 물 증가
		visited[clouds[c].x][clouds[c].y] = true;
	}
}

void copyWaterMagic(void) {
	for (Node cur : clouds) {
		int wCnt = 0;
		// 인접한 대각선 확인
		for (int k = 2; k <= 8; k += 2) {
			int nextX = cur.x + dx[k];
			int nextY = cur.y + dy[k];
			// 경계선 안에서
			if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= N)
				continue;

			// 물이 존재하는 경우
			if (map[nextX][nextY])
				wCnt++;
		}
		map[cur.x][cur.y] += wCnt;
	}
}

void createNewCloud() {
	vector<Node> preList = clouds;
	clouds.clear();
	for (int r = 0; r < N; r++)
	{
		for (int c = 0; c < N; c++)
		{
			// 기존 구름이 있었던 곳이나 물 양이 부족한 경우
			if (visited[r][c] || map[r][c] < 2)
				continue;

			clouds.push_back({ r, c });
			map[r][c] -= 2;
		}
	}

	// 이전 구름이 위치한 곳을 
	for (Node cur : preList)
	{
		visited[cur.x][cur.y] = false;
	}
	preList.clear();

}

int getTotalWater()
{
	int ret = 0;
	for (int r = 0; r < N; r++)
	{
		for (int c = 0; c < N; c++)
		{
			ret += map[r][c];
		}
	}
	return ret;
}

int main(void)
{
	input();
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &d, &s);
		moveClouds(d, s); // d 방향으로 s 만큼 구름 이동
		copyWaterMagic(); // 인접한 대각선 칸에 따른 처리
		createNewCloud(); // 새로운 구름 생성
	}
	printf("%d\n", getTotalWater());
	return 0;
}