#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 20;
const int SCENT_MAX = 1000;

struct Scent {
	int shark_idx, time;
};

struct State {
	int y, x;
	int shark_idx, time;
};

bool cmp(State a, State b) {
	return a.shark_idx < b.shark_idx;
}

int N, M, K;
int shark_tank[MAX][MAX]; // board(상어 번호가 담겨있음)
int shark_direction[MAX * MAX + 1]; // 상어의 방향
int move_priority[MAX * MAX + 1][5][4]; // [상어 번호][현재 방향][현재 방향에 따른 우선순위 방향]
Scent shark_scents[MAX][MAX]; // 상어 냄새의 흔적

int dy[5] = { 0,-1,1,0,0 };
int dx[5] = { 0,0,0,-1,1 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M >> K; // 맵크기(N*N), 상어갯수(M), 향수 지속력(K)

	/* *** INPUT *** */
	for (int i = 0; i < N; i++) { 
		for (int j = 0; j < N; j++) {
			int shark_idx;
			cin >> shark_idx;

			if (shark_idx == 0) continue; // 빈칸

			shark_tank[i][j] = shark_idx;// shark 보드에 shark의 
			shark_scents[i][j] = { shark_idx, K }; // 샤크 향기, 
		}
	}

	for (int i = 1; i <= M; i++) // 각 상어의 방향(상어 4마리니까 4개)
		cin >> shark_direction[i];

	for (int i = 1; i <= M; i++) // 각 상어의
		for (int j = 1; j <= 4; j++) // 4개의 좌표(방향 우선순위) - 각 행 : 위, 아래, 왼, 오
			for (int k = 0; k < 4; k++) {
				int move;
				cin >> move; // 방향 우선순위
				move_priority[i][j][k] = move;// [상어번호][방향][k] = move
			}

	/* *** INPUT *** */
	for (int time = 1; time <= 1000; time++) {
	
		vector<State> v;

		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				if (shark_tank[y][x] == 0) continue; // 상어가 없으면 pass~
				
				// 상어 이동
				bool flag = false;
				int shark_idx = shark_tank[y][x];
				int dir = shark_direction[shark_idx];

				// 이동
				shark_tank[y][x] = 0; // 시작 자리는 비움

				// 냄새 없는 칸으로 이동
				for (int k = 0; k < 4; k++) {
					int move = move_priority[shark_idx][dir][k];
					int ny = y + dy[move];
					int nx = x + dx[move];
					
					if (!(ny >= 0 && ny < N && nx >= 0 && nx < N)) continue;
					
					if (shark_scents[ny][nx].time) continue; // time 만료 -> continue

					flag = true;

					v.push_back({ ny, nx, shark_idx, K });
					shark_direction[shark_idx] = move;

					break;

				}
				
				if (flag) continue;
				
				// 자신의 냄새가 있는 곳으로 이동
				for (int k = 0; k < 4; k++) {
					int move = move_priority[shark_idx][dir][k];
					int ny = y + dy[move];
					int nx = x + dx[move];

					if (!(ny >= 0 && ny < N && nx >= 0 && nx < N)) continue;

					if (shark_scents[ny][nx].shark_idx != shark_idx) continue; // time 만료 -> continue
					
					v.push_back({ ny, nx, shark_idx, K });
					shark_direction[shark_idx] = move;

					break;
				}
			}
		}

		// 냄새 제거
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				if (shark_scents[y][x].time == 0) continue;
				int shark_idx = shark_scents[y][x].shark_idx;
				shark_scents[y][x].time--;
			}
		}

		sort(v.begin(), v.end(), cmp);

		for (int i = 0; i < v.size(); i++) {
			int y = v[i].y;
			int x = v[i].x;
			int shark_idx = v[i].shark_idx;

			if (shark_tank[y][x]) {
				M--;
				continue;
			}

			shark_tank[y][x] = shark_idx;
			shark_scents[y][x] = { shark_idx, K };
		}

		if (M == 1) {
			cout << time << "\n";
			return 0;
		}
	}

	cout << -1 << "\n";

	return 0;
}