#include <iostream>
#include <vector>

using namespace std;

int map[101][101];

typedef struct pos {
	int y;
	int x;
}Pos;

Pos dir[4] = { {0,1 },{-1,0},{0,-1},{1,0} };
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N; 
	int x, y, d, g;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x >> y >> d >> g;
		vector<Pos> v_pos;
		v_pos.push_back({ y,x });
		v_pos.push_back({ y + dir[d].y ,x + dir[d].x});
		map[y][x] = 1;
		map[y + dir[d].y ][x + dir[d].x] = 1;
		for (int j = 0; j < g; j++) { // µå·¡°ïÄ¿ºê È½¼ö
			vector<Pos> v_t;
			for (int n = v_pos.size() - 1; n > 0; n--) {
				Pos t;
				t.x = (v_pos[n].y - v_pos[n - 1].y);
				t.y = (v_pos[n].x - v_pos[n - 1].x) * -1;
				Pos next = { v_pos.back().y + t.y , v_pos.back().x + t.x };
				if (next.y >= 0 && next.x >= 0 && next.y <= 100 && next.x <= 100) {
					v_pos.push_back({ next.y, next.x });
					map[next.y][next.x] = 1;
				}
			}
		}
	}
	int count = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (map[i][j] && map[i + 1][j] && map[i][j + 1] && map[i + 1][j + 1])
				count++;
		}
	}
	cout << count << endl;
	return 0;
}