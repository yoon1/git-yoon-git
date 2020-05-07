#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 101

using namespace std;

typedef struct pos {
	int r;
	int c;
} Pos;
typedef struct shark {
	int s;
	int d;
	int z;
} Shark;

int R, C, M;

int map[MAX][MAX];
int king_pos = 0;
//vector<Shark> sharks[MAX][MAX];
Shark sharks[MAX][MAX];
int rslt = 0;

Pos dirs[5] = { {0,0}, {-1,0}, {1,0}, {0,1}, {0,-1} };

void moving_shark() { // ªÛæÓ¿« ¿Ãµø
	Shark t_sharks[MAX][MAX] = { 0 };

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (map[i][j] >= king_pos) { 
				Pos cur = { i, j };
				Shark info = sharks[i][j];
				// ¿Ãµø
				if (info.d <= 2) { // ¿ß, æ∆∑°
					int move = info.s % ((R - 1) * 2);
					for (int m = 0; m < move; m++) {
						Pos next = { cur.r + dirs[info.d].r , cur.c + dirs[info.d].c };
						if ( next.r < 1) {
							info.d = 2; // ¿ß -> æ∆∑° 
							next.r = 2;
						}
						if (next.r > R) {
							info.d = 1; // æ∆∑° -> ¿ß
							next.r = R - 1;
						}
						cur = next;
					}
				}
				else { // ø¿, øﬁ
					int move = info.s % ((C - 1) * 2);
					for (int m = 0; m < move; m++) {
						Pos next = { cur.r + dirs[info.d].r , cur.c + dirs[info.d].c };
						if (next.c < 1) { 
							info.d = 3;// øﬁ -> ø¿
							next.c = 2;
						}
						if (next.c > C) {
							info.d = 4;// ø¿ -> øﬁ
							next.c = C - 1;
						}
						cur = next;
					}
				}
				map[cur.r][cur.c] = king_pos+1;
				if (t_sharks[cur.r][cur.c].z < info.z)
					t_sharks[cur.r][cur.c] = info;
			}
		}
	}

	//copy
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			sharks[i][j] = t_sharks[i][j];
		}
	}
}

void fishing() {
	for (int r = 1; r <= R; r++) {
		if (map[r][king_pos] == king_pos) { // ªÛæÓ ¿÷¿∏∏È?
			rslt += sharks[r][king_pos].z;
			map[r][king_pos] = 0;
			sharks[r][king_pos] = Shark{ 0,0,0 };
			return ;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int r, c, s, d, z;
	
	cin >> R >> C >> M;
	for (int i = 0; i < M; i++) {
		cin >> r >> c >> s >> d >> z;
		map[r][c] = 1;
		sharks[r][c] = Shark{ s,d,z };
	}

	// ≥¨Ω√ø’¿« ¿Ãµø
	for (king_pos= 1; king_pos <= C; king_pos++) {
		// ≥¨Ω√ø’¿« ≥¨Ω√
		fishing();
		// ¿Ãµø
		moving_shark();
	}
	
	cout << rslt << endl;
	return 0;
}