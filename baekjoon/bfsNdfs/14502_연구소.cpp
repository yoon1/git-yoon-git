#include <iostream>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <vector>
#define MAX 10

using namespace std;

pair<int, int> dir[4] = { make_pair(0,1), make_pair(1,0), make_pair(0,-1), make_pair(-1,0) };
queue<pair<int, int>> q;
vector<pair<int, int>> virus;
int N, M;
int map[MAX][MAX] = { 0 };
int tMap[MAX][MAX] = { 0 };
int safeCount = 0;

bool isRange(int y, int x) {
	if (y >= 0 && y < N && x >= 0 && x < M) {
		return true;
	}
	return false;
}

void bfs() {
	int wall_map[MAX][MAX];
	memcpy(wall_map, tMap, sizeof(tMap));
	queue<pair<int, int>> q;
	for (int i = 0; i < virus.size(); i++) 
		q.push(virus[i]);
	while (!q.empty()) {
		pair<int, int> cur = make_pair(q.front().first, q.front().second);
		q.pop();
		for (int i = 0; i < 4; i++){
			int nextY = cur.first + dir[i].first;
			int nextX = cur.second + dir[i].second;
			if (isRange(nextY, nextX)) {
				if (wall_map[nextY][nextX] == 0) {
					wall_map[nextY][nextX] = 2;
					q.push(make_pair(nextY, nextX));
				}
			}
		}
	}

	int curSafeCount = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if ( wall_map[i][j] == 0 ) 
				curSafeCount++;
		}
	}

	safeCount = max(safeCount, curSafeCount);
}

void makeWall(int depth) {
	if (depth == 3) {
		bfs();
		return;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (tMap[i][j] == 0) {
				tMap[i][j] = 1;
				makeWall(depth + 1);
				tMap[i][j] = 0;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2)
				virus.push_back(make_pair(i, j));
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0)
			{
				memcpy(tMap, map, sizeof(map));
				tMap[i][j] = 1;
				makeWall(1);
				tMap[i][j] = 0;
			}
		}
	}

	cout << safeCount << endl;

	return 0;
}
