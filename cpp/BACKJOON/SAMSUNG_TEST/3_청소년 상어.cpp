#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;

struct Fish{
	int y, x;
	int d; 
};

int dy[8] = { -1, -1, 0, +1, +1, +1, 0, -1 };
int dx[8] = { 0, -1, -1, -1, 0, +1, +1, +1 };
int board[4][4];
Fish fish[16];
int ret;

void go(int board[4][4], Fish fish[], int sy, int sx, int sum) {
	int t_board[4][4];
	Fish t_fish[16];
	//memcpy(t_board, board, sizeof(t_board));
	//memcpy(t_fish, fish, sizeof(t_fish));
	for (int y = 0; y < 4; y++)
		for (int x = 0; x < 4; x++)
			t_board[y][x] = board[y][x];

	for (int i = 0; i < 16; i++)
		t_fish[i] = fish[i];

	// eat
	int fish_num = t_board[sy][sx];
	int sd = t_fish[fish_num].d;

	t_fish[fish_num].y = -1;
	t_fish[fish_num].x = -1;
	t_fish[fish_num].d = -1;

	t_board[sy][sx] = -1;

	sum += (fish_num + 1);
	ret = max(sum, ret);

	// fish move
	for (int f = 0; f < 16; f++) {
		if (t_fish[f].y == -1) continue;
		int cy = t_fish[f].y;
		int cx = t_fish[f].x;
		//int cd = t_fish[f].d;
		
		int nd = t_fish[f].d;
		int ny = cy + dy[nd];
		int nx = cx + dx[nd];
		

		while (!(ny >= 0 && ny < 4 && nx >= 0 && nx < 4) || (sy == ny && sx == nx) ) {
			nd = (nd + 1) % 8;
			ny = cy + dy[nd];
			nx = cx + dx[nd];
		}

		int target = t_board[ny][nx];
		if (target != -1) { // 물고기 있 - 자리 바꿈
			t_fish[target].y = cy;
			t_fish[target].x = cx;
		}
		t_fish[f].y = ny;
		t_fish[f].x = nx;
		t_fish[f].d = nd;
		
		t_board[ny][nx] = f;
		t_board[cy][cx] = target;
	}

	// shark move
	for (int step = 1; step < 4; step++) {
		int ny = sy + dy[sd] * step;
		int nx = sx + dx[sd] * step;
		if (!(ny >= 0 && ny < 4 && nx >= 0 && nx < 4)) break;
		if ( t_board[ny][nx] != -1) 
			go(t_board, t_fish, ny, nx, sum);
	}
}

int main() {
	int a, b;
	for(int y = 0; y < 4; y++)
		for (int x = 0; x < 4; x++) {
			cin >> a >> b;
			a--, b--;
			board[y][x] = a;
			fish[a] = { y,x,b };
		}
	
	ret = 0;

	go(board, fish, 0, 0, 0);

	cout << ret << endl;
	return 0;
}

