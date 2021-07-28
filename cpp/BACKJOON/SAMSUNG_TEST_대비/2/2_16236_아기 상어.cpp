#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct pos {
	int y, x, d;
};
struct fishes {
	int y, x, size, d;
};

int map[20][20];
int N;
pos shark;
int dy[4] = { 0,0,-1,1 };
int dx[4] = { -1,1,0,0 };

int move(int size) {
	pos start = { shark.y, shark.x, 0 }; // 상어 초기 위치
	queue<pos> q; // 상어의 위치
	q.push(start);
	bool visited[20][20] = { false };
	vector<fishes> vf; // 크기, y, x

	while (!q.empty()) {
		int cy = q.front().y;
		int cx = q.front().x;
		int cd = q.front().d;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			int nd = cd + 1;
			if (!vf.empty() && vf.back().d > nd) break;
			if (!(ny >= 0 && ny < N && nx >= 0 && nx < N)) continue;
			if (visited[ny][nx]) continue;
			visited[ny][nx] = true;

			if (map[ny][nx] > size) continue;
			if (map[ny][nx] > 0 && map[ny][nx] < size) {
				vf.push_back({ ny, nx, map[ny][nx], nd });
			}
			q.push({ ny, nx, nd });
		}
	}

	if (vf.empty())
		return 0;
	// 어디로 이동할까?
	fishes target = { N,N,0,N * N };
	for (int i = 0; i < vf.size(); i++) {
		if (vf[i].d < target.d)
			target = vf[i];
		else if (vf[i].d == target.d) {
			if (vf[i].y < target.y) 
				target = vf[i];
			else if (vf[i].y == target.y) 
				if (vf[i].x < target.x) 
					target = vf[i];
		}
	}
	map[target.y][target.x] = 0;
	shark = { target.y, target.x, 0 };
	return target.d;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				shark = { i,j,0 };  // shark의 좌표 및 사이즈 초기화
				map[i][j] = 0;
			}
		}
	}
	int size = 2; // 상어의 크기
	int eat = 0; // 먹은 물고기 갯수
	int time = 0;
	while (1) {
		int t = move(size);
		if (t == 0) break; // 이동 X
		if (++eat >= size) {
			size++;
			eat = 0;
		}
		time += t;
	}

	cout << time;
	return 0;
}