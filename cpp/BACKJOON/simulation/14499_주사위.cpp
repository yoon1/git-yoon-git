#include <iostream>
using namespace std;

int N, M;
int map[20][20];

int main() {
	int dice[6] = { 0 };
	int t_dice[6] = { 0 };
	int diceMap[4][6] = { 
							{ 4, 2, 1, 6, 5, 3},
							{ 3, 2, 6, 1, 5, 4},
							{ 5, 1, 3, 4, 6, 2},
							{ 2, 6, 3, 4, 1, 5}
						};
	
	pair<int, int> dir[4] = { {0,1}, {0,-1} ,{-1,0}, {1,0} };
	int x, y, K;
	cin >> N >> M >> y >> x >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < K; i++) {
		int t;
		cin >> t; // 방향 입력.
		y += dir[t - 1].first; // 좌표 설정
		x += dir[t - 1].second;
		if (!(x >= 0 && y >= 0 && y < N && x < M)) { // map 범위 내인가?
			y -= dir[t - 1].first;
			x -= dir[t - 1].second;
			continue;
		}
		for (int i = 0; i < 6; i++) {
			t_dice[i] = dice[i];
		}
		for (int i = 0; i < 6; i++) {
			dice[i] = t_dice[diceMap[t-1][i]-1];
		}
		// 상단 점수 출력
		cout << dice[0] << endl;
		if (map[y][x] == 0)
		{
			map[y][x] = dice[5];
		}
		else {
			dice[5] = map[y][x];
			map[y][x] = 0;
		}	
	}
	return 0;
}
