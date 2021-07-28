#include <iostream>
#include <queue>
#define MAX 300
using namespace std;

int N, M;
int map[MAX][MAX];
bool visited[MAX][MAX];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
struct pos {
	int y, x;
};

// ∫˘«œ ≥Ï¿Ω
bool melt() {
	bool ret = false;
	int melt[MAX][MAX];
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			melt[y][x] = 0;
			if (!(map[y][x] > 0)) continue;
			for (int d = 0; d < 4; d++) {
				int ny = y + dy[d];
				int nx = x + dx[d];
				if (!(ny >= 0 && nx >= 0 && ny < N && nx < M)) continue;
				if (map[ny][nx] == 0) {
					melt[y][x]++;
					ret = true;
				}
			}
		}
	}
	if (!ret) return ret;

	for (int y = 0; y < N; y++) 
		for (int x = 0; x < M; x++) 
			map[y][x] = ( map[y][x] - melt[y][x] ) > 0 ? map[y][x] - melt[y][x] : 0;
	
	return ret;
}

void bfs(int sy, int sx) {
	queue<pos> q; 
	//Ω√¿€
	q.push({ sy, sx });
	visited[sy][sx] = true;
	while(!q.empty()) {
		pos cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {	
			int ny = cur.y + dy[i];
			int nx = cur.x + dx[i];
			if (!(ny >= 0 && nx >= 0 && ny < N && nx < M)) continue;
			if (visited[ny][nx]) continue;
			if (!(map[ny][nx] > 0)) continue;
			visited[ny][nx] = true;
			q.push({ ny,nx });
		}
	}
}

//visited √ ±‚»≠
void init() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			visited[i][j] = false;
}

void print_() {
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {
	// input
	cin >> N >> M;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visited[i][j] = false;
			scanf("%d", &map[i][j]);
		}
	}

	int cnt;
	int time = 0;
	do{
		cnt = 0;
		init();
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (!visited[i][j] && map[i][j] > 0) {
					cnt++;
					bfs(i, j);
				}
			}
		}
		// melt
		if (!melt()) {
			cout << 0;
			return 0;
		}
		//cout << "===========" << endl;
		//print_();
		
	} while (cnt == 1 && ++time);
	cout << time;
	return 0;
}