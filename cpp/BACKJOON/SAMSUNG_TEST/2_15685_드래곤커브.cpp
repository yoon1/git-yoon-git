#include <iostream>
#include <vector>

using namespace std;

struct Pos {
	int y, x;
};

int map[101][101];
// 오른쪽, 위, 왼쪽, 아래
int dy[4] = { 0, -1, 0, 1 };
int dx[4] = { 1, 0, -1, 0 }; 

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	int x, y, d, g;
	cin >> N;

	for (int i = 0; i < N; i++) { // 
		cin >> x >> y >> d >> g;
		vector<Pos> v;
		v.push_back({ y, x }); 
		v.push_back({ y + dy[d], x + dx[d] }); // 초기값 세팅
		
		map[y][x] = 1; // 초기값
		map[y + dy[d]][x + dx[d]] = 1; // 초기값 

		for (int j = 0; j < g; j++) { // 세대(드래곤커브 횟수)
			int py = v.back().y, px = v.back().x;
			for (int n = v.size() - 1; n >= 0; n--) {
				int cy = v[n].y, cx = v[n].x;

				int ny = cx - px + py;
				int nx = -cy + px + py;
				
				if (!(ny >= 0 && ny <= 100 && nx >= 0 && nx <= 100)) continue;
				v.push_back({ ny, nx });
				map[ny][nx] = 1;
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