#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

struct Pos {
	int r;
	int c;
	int d;
};
int R, C;
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0, -1, 0, 1 };
char map[50][50];
int water_map[50][50];
bool visited[50][50];

bool isPossible(Pos pos) {
	if (!(pos.r >= 0 && pos.r < R && pos.c >= 0 && pos.c < C)) return false;
	return true;
}

int main() {
	cin >> R >> C;
	queue<Pos> water;
	queue<Pos> hog;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			water_map[i][j] = -1;
			scanf("%1s", &map[i][j]);
			if (map[i][j] == 'S') {
				hog.push({ i,j,0 });
				visited[i][j] = true;
			}
			else if (map[i][j] == '*') {
				water_map[i][j] = 0;
				water.push({ i,j,0 });
			}
		}
	}

	while (!water.empty()) {
		Pos cur = water.front();
		water.pop();
		//water_map[cur.r][cur.c] = cur.d;
		for (int i = 0; i < 4; i++) {
			Pos next = { cur.r + dr[i] , cur.c + dc[i] , cur.d + 1 }; // 다음 좌표!
			if (isPossible(next)) {
				if (water_map[next.r][next.c] == -1 // 물
					&& map[next.r][next.c] != 'D'  // 비버 집
					&& map[next.r][next.c] != 'X') // 돌
				{
					water.push(next);
					water_map[next.r][next.c] = next.d;
				}
			}
		}
	}
	
	/* for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << water_map[i][j] << " ";
		}
		cout << endl;
	} */

	while (!hog.empty()) {
		Pos cur = hog.front();
		hog.pop();
		visited[cur.r][cur.c] = true;
		//cout << cur.r << "," << cur.c << endl;
		if (map[cur.r][cur.c] == 'D') {
			cout << cur.d << "\n";
			return 0;
		}
		for (int i = 0; i < 4; i++) {
			Pos next = { cur.r + dr[i] , cur.c + dc[i] , cur.d + 1 }; // 다음 좌표!
			if (isPossible(next)) {
				// 다음으로 가는 길에 물이 있으면 안됨..
				if (((water_map[next.r][next.c] > next.d)
					 || (water_map[next.r][next.c] == -1))
					&& map[next.r][next.c] != 'X'
					&& !visited[next.r][next.c]) {
					visited[next.r][next.c] = true;
					hog.push(next);
				}
			}
		}
	}
	cout << "KAKTUS" << "\n";
	return 0;

}