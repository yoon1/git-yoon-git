#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Fish {
	int y;
	int x;
	int d;
};
//  ↑, ↖, ←, ↙, ↓, ↘, →, ↗
int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx[8] = {0, -1, -1, -1, 0, 1, 1, 1};

int ret;

void go(int board[4][4], Fish fish[], int sy, int sx, int point) {
	//cout << sy << sx << endl;
	int t_board[4][4];
	Fish t_fish[16];
	// 초기화
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			t_board[i][j] = board[i][j];
	for (int i = 0; i < 16; i++)
		t_fish[i] = fish[i];

	// eat
	int fish_num = t_board[sy][sx]; 
	int sd = t_fish[fish_num].d;

	t_fish[fish_num].y = -1;
	t_fish[fish_num].x = -1;
	t_fish[fish_num].d = -1;
	
	t_board[sy][sx] = -1;

	point += (fish_num + 1);
	ret = max(ret, point);

	// fish move
	for (int i = 0; i < 16; i++) {
		if (t_fish[i].y == -1) continue; 
		int cy = t_fish[i].y;
		int cx = t_fish[i].x;
		int cd = t_fish[i].d;

		int ny = cy + dy[cd];
		int nx = cx + dx[cd];
		int nd = cd;

		while (!(ny >= 0 && ny < 4 && nx >= 0 && nx < 4) // 막혀있거나
			|| (ny == sy && nx == sx)) { // 상어의 위치면?
			nd = (nd + 1) % 8;
			ny = cy + dy[nd];
			nx = cx + dx[nd];
		}

		int target = t_board[ny][nx];

		if (target != -1) { //물고기가 있으면? -> 자리 바꿔주기
			t_fish[target].y = cy;
			t_fish[target].x = cx;
		}

		t_fish[i].y = ny;
		t_fish[i].x = nx;
		t_fish[i].d = nd;

		t_board[ny][nx] = i;
		t_board[cy][cx] = target;
	}

	// shark move
	for (int step = 1; step < 4; step++) {
		int ny = sy + dy[sd] * step;
		int nx = sx + dx[sd] * step;
		if (!(ny >= 0 && ny < 4 && nx >= 0 && nx < 4))
			break;
		if (t_board[ny][nx] != -1)
			go(t_board, t_fish, ny, nx, point);
	}
}

int main() {
	int a, b;
	int board[4][4];
	Fish fish[16]; // 16마리

	ret = 0;

	for (int i = 0; i < 4; i++) {
		for(int j = 0; j < 4; j++){
			cin >> a >> b;
			--a, --b;
			fish[a] = { i,j,b }; // 물고기가 차례로 이동해야함
			board[i][j] = a; // 물고기 number
		}
	}

	go(board, fish, 0, 0, 0); // shark_y, shark_x, 물고기 번호 합

	cout << ret << endl;
	return 0;
}
