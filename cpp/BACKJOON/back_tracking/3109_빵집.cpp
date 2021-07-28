#include <iostream>
#include <algorithm>

using namespace std;

typedef struct pos{
	int y;
	int x;
}Pos;

Pos dir[3] = { {-1,1},{0,1},{1,1} }; // 위, 중간, 아래
int R, C;
char map[10000][500];
int cnt = 0;

bool isPromising(Pos next) {
	if (next.y >= 0 && next.y < R && next.x >= 0 && next.x < C ) 
		if ( map[next.y][next.x] == '.')
			return true;	
	return false;
}
bool back_tracking(int y, int x) {
	map[y][x] = 'p';
	if (x == C - 1) return true;
	for (int i = 0; i < 3; i++) {
		Pos next = { y + dir[i].y, x + dir[i].x };
		if ( isPromising(next) ) {
			if (back_tracking(next.y, next.x))
				return true;
		}
	}
	return false;
}
int main() {
	cin >> R >> C;   
	for (int i = 0; i < R; i++) 
		for (int j = 0; j < C; j++)
			cin >> map[i][j];

	for (int i = 0; i < R; i++)
		if (back_tracking(i, 0))
			cnt++;

	cout << cnt << endl;
	return 0;
}