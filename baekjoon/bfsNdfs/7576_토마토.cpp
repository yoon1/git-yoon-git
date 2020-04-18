#include <iostream>
#include <algorithm>
#include <queue>
#define MAX 1000

// tomato

using namespace std;


pair<int, int> dir[4] = { make_pair(0,1), make_pair(1,0), make_pair(0,-1), make_pair(-1,0) };
int N, M;
int map[MAX][MAX];
int visited[MAX][MAX];
queue<pair<pair<int, int>, int>> good_tomatoes;

bool isRange(int y, int x) {
	if (y < N &&  y >= 0 && x < M && x >= 0) {
		return true;
	}
	return false;
	
}

int bfs() {
	int maxDepth = 0;
	while (!good_tomatoes.empty()) {
		pair<pair<int, int>, int> cur = good_tomatoes.front();
		int curY = cur.first.first;
		int curX = cur.first.second;
		int curDepth = cur.second;
		maxDepth = max(curDepth, maxDepth);
		good_tomatoes.pop();
		for (int i = 0; i < 4; i++) {
			int nextY = curY + dir[i].first;
			int nextX = curX + dir[i].second;
			if (isRange(nextY, nextX)) {
				if (map[nextY][nextX] == 0){
					map[nextY][nextX] = 1;
					good_tomatoes.push(make_pair(make_pair(nextY, nextX), curDepth + 1));
				}
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0)
				return -1;
		}
	}
	return maxDepth;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if ( map[i][j] == 1) 
				good_tomatoes.push(make_pair(make_pair(i,j), 0));
		}
	}

	int result = bfs() ;
	cout << result;
	return 0;
}