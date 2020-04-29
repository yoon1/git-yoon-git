#include <iostream>
#include <memory.h>
#include <vector>

using namespace std;

typedef struct dir {
	int y;
	int x;
}Dir;

int room[50][50];
int R, C, T;
Dir dir[2][4] = { { {0,1},{-1,0},{0,-1},{1,0}}, {{0,1}, {1,0} ,{0,-1}, {-1,0}}};
// 동 북 서 남  , 동 남 서 북
vector<Dir> airController;

void countDust() {
	int total = 0;
	for (int i = 0; i < R; i++) 
		for (int j = 0; j < C; j++) {
			if ( room[i][j] > 0 ) 
				total += room[i][j];
		}
	cout << total << endl;
}

void move() {
	int t_room[50][50] = { 0 };
	memcpy(t_room, room, sizeof(room));
	for (int air = 0; air < airController.size(); air++) {
		Dir cur = { airController[air].y , airController[air].x };
		for (int i = 0; i < 4; i++) {
			while (1) {
				Dir next = { cur.y + dir[air][i].y , cur.x + dir[air][i].x };
				if (next.y >= 0 && next.x >= 0 && next.y < R && next.x < C
					&& t_room[next.y][next.x] >= 0 ) {				
					t_room[next.y][next.x] = room[cur.y][cur.x];
					if (t_room[cur.y][cur.x] == -1)
						t_room[next.y][next.x] = 0;
					cur = next;
				}
				else
					break;
			}
		}
	}
	memcpy(room, t_room, sizeof(room));
}

void spread() {
	int t_room[50][50] = { 0 };
	t_room[airController[0].y][airController[0].x] = -1;
	t_room[airController[1].y][airController[1].x] = -1;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (room[i][j] > 0) {
				Dir cur = { i,j };
				vector<Dir> around;
				for (int n = 0; n < 4; n++) {
					Dir next = { cur.y + dir[0][n].y, cur.x + dir[0][n].x };
					if (next.y >= 0 && next.x >= 0 && next.y < R && next.x < C) {
						if (room[next.y][next.x] >= 0) {
							around.push_back({ next.y, next.x });
						}
					}
				}
				int cur_dust = room[i][j];
				int around_dust = cur_dust / 5;
				for (int n = 0; n < around.size(); n++) {
					t_room[around[n].y][around[n].x] += around_dust;
					cur_dust -= around_dust;
				}
				t_room[i][j] += cur_dust;
			}
		}
	}
	memcpy(room, t_room, sizeof(room));
}

int main() {
	cin >> R >> C >> T;
	for (int i = 0; i < R; i++) {
		for (int j= 0; j < C; j++) {
			cin >> room[i][j];
			if ( room[i][j] == -1) 
				airController.push_back({ i, j }); // air controller 좌표 등록.
		}
	}
	for (int time = 0; time < T; time++) {
	// 확산 
		spread();
	// 공기청정기 작동
		move();
	}
	countDust();
	return 0;
 }