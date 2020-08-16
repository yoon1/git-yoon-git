#include <iostream>
#include <queue>
using namespace std;


struct pos {
	int y;
	int x;
};
pos dir[4] = { {0,1}, {0,-1},{1,0},{-1,0} };

int main() {
	int T;
	int M, N, K;
	cin >> T;
	for(int testCase = 0; testCase < T; testCase++) {
		int answer = 0;
		cin >> M >> N >> K;
		bool visited[50][50] = { false };
		int map[50][50] = { 0 } ;
		for (int i = 0; i < K; i++) {
			int row, col;
			cin >> row >> col;
			map[row][col] = 1;
		}

		queue<pos> q;

		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] == 1 && !visited[i][j]) {
					q.push({ i,j });
					while (!q.empty()) {
						pos cur = q.front();
						q.pop();
						for (int k = 0; k < 4; k++) {
							pos next = { cur.y + dir[k].y, cur.x + dir[k].x };
							if (next.y < 0 || next.y >= M || next.x < 0 || next.x >= N) continue;
							if (visited[next.y][next.x]) continue;
							if (map[next.y][next.x] == 1) {
								visited[next.y][next.x] = true;
								q.push({ next.y, next.x });
							}
						}
					}
					answer++;
				}
			}
		}
		cout << answer << endl;
	}
	return 0;
}