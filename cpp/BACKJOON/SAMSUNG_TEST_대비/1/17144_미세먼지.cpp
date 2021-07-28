#include <iostream>
#include <vector>

using namespace std;

struct pos{
	int y;
	int x;
};
int R, C, T;
int map[50][50];
vector<int> airmachine;
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };

// 시계 : 오, 위, 왼, 아
// 반시계 : 오, 아, 왼, 위 
vector<pos> dust;

void wind(int type) {
	pos start = { airmachine[type], 0 };
	for (int i = 0; i < 4; i++) {
		int ddy = (type == 1 && i%2 == 1) ? -dy[i] : dy[i];
		int ddx = dx[i];
		while (1) {
			start.y += ddy;
			start.x += ddx;
			if (!(start.y >= 0 && start.y < R && start.x >= 0 && start.x < 0)) {
				start.y -= ddy;
				start.x -= ddx;
				break;
			}
		}
	}
}
void onAirMachine(){
	for (int i = 0; i < 2; i++) {
		wind(i);
	}	
}

void spreadDust() {
	for (int i = 0; i < dust.size(); i++) {
		pos curDust = dust[i];
		for (int i = 0; i < 4; i++) {
			curDust = { curDust.y + dy[i], curDust.x + dx[i] };

		}
	}
}

int main() {
	
	cin >> R >> C >> T;
	for (int testCase = 0; testCase < T; testCase++) {
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				cin >> map[i][j];
				if (map[i][j] == -1) 
					airmachine.push_back(i);
				if (map[i][j] > 0)
					dust.push_back({ i, j }); // dust 좌표
			}
		}
	}
	spreadDust(); // 확산
	onAirMachine();
	return 0;
}