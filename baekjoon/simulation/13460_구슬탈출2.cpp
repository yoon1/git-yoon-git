#include <iostream>
#include <queue>

using namespace std;

typedef struct balls {
	int ry;
	int rx;
	int by;
	int bx;
	int depth;
}Balls;

typedef struct pos {
	int y;
	int x;
}Pos;
int N, M;
char map[10][10];
bool visited[10][10][10][10]; // 공에 대한 visited
queue<Balls> q;
Pos dirs[4] = { {-1,0},{1,0},{0,-1},{0,1} };

void move(int &y, int &x, int &m, int dy, int dx) {
	//int dy = dirs[d].y, dx = dirs[d].x; // 이동
	while (map[y][x] != 'O') {
		if (map[y + dy][x + dx] == '#') break;
		y += dy; // x이동
		x += dx; // y이동
		m += 1; // 1이동
	}
}
void bfs() {
	while (!q.empty()) {
		int c_ry = q.front().ry, c_rx = q.front().rx;
		int c_by = q.front().by, c_bx = q.front().bx;
		int c_d = q.front().depth;
		q.pop();
		if (c_d > 10) break; // 10회이상 no - bfs라서 처음 10회가 넘어가는 순간 끝임
		if (map[c_ry][c_rx] == 'O') { cout << c_d;  return; } // yes
		for (int i = 0; i < 4; i++) {
			int dy = dirs[i].y, dx = dirs[i].x;
			int n_ry = c_ry, n_rx = c_rx, n_by = c_by, n_bx = c_bx; // 다음
			int m_r = 0, m_b = 0;
			move(n_ry, n_rx, m_r, dy, dx);
			move(n_by, n_bx, m_b, dy, dx);

			if (map[n_by][n_bx] == 'O') continue; // blue가 hole에 빠지면 끝;

			// 겹칠 경우에 대한 처리
			if (n_ry == n_by && n_rx == n_bx) {
				if (m_r > m_b) { n_ry -= dy; n_rx -= dx; }
				else { n_by -= dy; n_bx -= dx; }
			}
			
			if (visited[n_ry][n_rx][n_by][n_bx]) continue;
			visited[n_ry][n_rx][n_by][n_bx] = true;
			q.push({ n_ry,n_rx,n_by,n_bx,c_d+1});
		}
	}
	cout << "-1";
}

int main() {
	int N, M;
	int ry, rx, by, bx;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'R') { ry = i; rx = j; } // red
			else if (map[i][j] == 'B') { by = i; bx = j; } // blue 
		}
	}
	q.push({ry,rx,by,bx,0});
	visited[ry][rx][by][bx] = true;
	bfs();
	return 0;
}