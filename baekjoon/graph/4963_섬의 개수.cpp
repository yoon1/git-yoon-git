#include <iostream>
#include <queue>
using namespace std;

typedef struct pos {
	int y;
	int x;
}Pos;
Pos dir[8] = { {-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1} };
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int w, h;
	while (1) {
		cin >> w >> h;
		if (w == 0 && h == 0) {
			break;
		}
		int map[50][50] = { 0 };
		bool visited[50][50] = { false };
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> map[i][j];
			}
		}
		int rslt = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (map[i][j] && !visited[i][j]) {
					queue<Pos> q;
					q.push({ i,j });
					visited[i][j] = true;
					while (!q.empty()) {
						Pos cur = q.front();
						q.pop();
						for (int i = 0; i < 8; i++) {
							Pos next = { cur.y + dir[i].y, cur.x + dir[i].x };
							if ( next.y >= 0 && next.x >= 0 && next.y < h && next.x < w )
								if (!visited[next.y][next.x] && map[next.y][next.x]) {
									visited[next.y][next.x] = true;
									q.push({ next.y, next.x });
								}
						}
					}
					rslt++;
				}
			}
		}
		cout << rslt << "\n";
	}
	return 0;
}