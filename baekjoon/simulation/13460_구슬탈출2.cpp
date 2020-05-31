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
bool visited[10][10][10][10]; // ���� ���� visited
queue<Balls> q;
Pos dirs[4] = { {-1,0},{1,0},{0,-1},{0,1} };

void move(int &y, int &x, int &m, int dy, int dx) {
	//int dy = dirs[d].y, dx = dirs[d].x; // �̵�
	while (map[y][x] != 'O') {
		if (map[y + dy][x + dx] == '#') break;
		y += dy; // x�̵�
		x += dx; // y�̵�
		m += 1; // 1�̵�
	}
}
void bfs() {
	while (!q.empty()) {
		int c_ry = q.front().ry, c_rx = q.front().rx;
		int c_by = q.front().by, c_bx = q.front().bx;
		int c_d = q.front().depth;
		q.pop();
		if (c_d > 10) break; // 10ȸ�̻� no - bfs�� ó�� 10ȸ�� �Ѿ�� ���� ����
		if (map[c_ry][c_rx] == 'O') { cout << c_d;  return; } // yes
		for (int i = 0; i < 4; i++) {
			int dy = dirs[i].y, dx = dirs[i].x;
			int n_ry = c_ry, n_rx = c_rx, n_by = c_by, n_bx = c_bx; // ����
			int m_r = 0, m_b = 0;
			move(n_ry, n_rx, m_r, dy, dx);
			move(n_by, n_bx, m_b, dy, dx);

			if (map[n_by][n_bx] == 'O') continue; // blue�� hole�� ������ ��;

			// ��ĥ ��쿡 ���� ó��
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