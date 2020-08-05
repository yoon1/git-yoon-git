#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

struct Pos{
	int r;
	int c;
};
int R, C;
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0, -1, 0, 1 };
char map[51][51];
bool visited[51][51];
queue<Pos> water;
queue<Pos> hog;
Pos goal;

bool isPossible(Pos pos) {
	if (pos.r >= 0 && pos.r < R && pos.c >= 0 && pos.c < C) return true;
	return false;
}

int main() {
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			scanf("%1s", &map[i][j]);
			if (map[i][j] == 'S') hog.push({ i,j });
			else if (map[i][j] == '*') water.push({ i,j});
			else if (map[i][j] == 'D') goal.r = i, goal.c = j;
		}
	}
	int cnt = 0;
	while (!hog.empty()) {
		cnt++;
		int water_size = water.size();
		while (water_size--) {
			Pos cur = water.front();
			water.pop();
			for (int i = 0; i < 4; i++) {
				Pos next = { cur.r + dr[i] , cur.c + dc[i]}; // ´ÙÀ½ ÁÂÇ¥!
				if (!isPossible(next)) continue;
				if (map[next.r][next.c] == 'X' || map[next.r][next.c] == 'D' || map[next.r][next.c] == '*') continue;
				water.push(next);
				map[next.r][next.c] = '*';
			}
		}

		int hog_size = hog.size();
		while(hog_size--){
			Pos cur = hog.front();
			hog.pop();
			visited[cur.r][cur.c] = true;
			if (goal.r == cur.r && goal.c == cur.c) {
				cout << ( cnt - 1 ) << endl;
				return 0;
			} 
			for (int i = 0; i < 4; i++) {
				Pos next = { cur.r + dr[i] , cur.c + dc[i] };
				if (!isPossible(next)) continue;
				if (map[next.r][next.c] == 'X' || map[next.r][next.c] == '*' || visited[next.r][next.c]) continue;
				visited[next.r][next.c] = true;
				hog.push(next);
			}
		}
	}
	cout << "KAKTUS" << "\n"; 
	return 0;
}