#include <iostream>
#include <map>
#define UP 1
#define DOWN 2
#define RIGHT 3
#define LEFT 4

using namespace std;

struct Shark {
	int s, d, z; // 속력, 방향, 크기
};

map <pair<int, int>, Shark > shark;
int ret;
int R, C, M;
int dy[5] = { 0, -1, 1, 0, 0 };
int dx[5] = { 0, 0, 0, 1, -1 };

void shark_move() {
	map <pair<int, int>, Shark > result;
	for (map <pair<int, int>, Shark >::iterator it = shark.begin(); it != shark.end(); it++) {
		pair<int, int> pos = it->first;
		pair<int, int> n_pos = pos;
		Shark cur = it->second;

		if (cur.d == UP || cur.d== DOWN) {
			int dist = cur.s % ((R - 1) * 2);
			for (int i = 0; i < dist; i++) {
				n_pos = { pos.first + dy[cur.d], pos.second + dx[cur.d] };
				if (n_pos.first < 1) { // 위 범위 초과
					cur.d = DOWN; 
					n_pos.first = 2;
				} 
				if (n_pos.first > R) { // 아래 범위 초과
					cur.d = UP;
					n_pos.first = R - 1;
				}
				pos = n_pos;
			}
		}
		else {
			int dist = cur.s % ((C - 1) * 2);
			for (int i = 0; i < dist; i++) {
				n_pos = { pos.first + dy[cur.d], pos.second + dx[cur.d] };
				if (n_pos.second < 1) { // 왼 범위 초과
					cur.d = RIGHT ; 
					n_pos.second = 2;
				}
				if (n_pos.second > C) { // 오른 범위 초과
					cur.d = LEFT;
					n_pos.second = C - 1;
				}
				pos = n_pos;
			}
		}

		if (result.find(n_pos) == result.end()) 
			result[n_pos] = cur;
		else
			if(result[n_pos].z <= cur.z) 
				result[n_pos] = cur;
	}
	shark = result;
}

void fishing(int c) {
	for (int r = 1; r <= R; r++) {
		pair<int, int> pos = { r, c };
		if (shark.find(pos) != shark.end()) // 있음
		{
			ret += shark[pos].z;
			shark.erase(pos); // 먹혔음 -> 제거
			break;
		}
	}
}

int main() {
	cin >> R >> C >> M;

	// 0. input
	for (int i = 0; i < M; i++) {
		int r, c, s, d, z;
		cin >> r >> c >> s >> d >> z;
		shark[{r, c}] = { s, d, z };
	}

	// 1. 낚시왕의 이동 (easy)
	for (int king = 1; king <= C; king++) {
		// 2. 상어 잡기 (easy)
		fishing(king);
		// 3. 상어 이동 (hard)
		shark_move();
	}

	cout << ret;
	return 0;
}