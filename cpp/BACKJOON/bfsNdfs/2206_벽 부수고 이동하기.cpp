#include <iostream>
#include <deque>
#define MAX 1001

using namespace std;

struct Position {
	int y;
	int x;
	int depth;
	bool pass;
} position ; 

int N, M;
char map[MAX][MAX];
bool visited[MAX][MAX][2];
deque<Position> q;
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };

bool checkRange(int y, int x) {
	if (y >= 0 && x >= 0 && y < N && x < M)
		return true;
	return false;
}

int  bfs() {
	struct Position position { 0, 0, 1, false };
	visited[0][0][0] = true;
	q.push_back(position);
	
	while (!q.empty()) {
		Position cur = q.front();
		q.pop_front();

		// Å»Ãâ!!
		if (cur.y == N - 1 && cur.x == M - 1)
			return cur.depth;
		for (int i = 0; i < 4; i++) {
			int next_y = cur.y + dy[i];
			int next_x = cur.x + dx[i];
			if (checkRange(next_y, next_x)){
				if (visited[next_y][next_x][cur.pass] && map[next_y][next_x] == '0') {
					q.push_back(Position{ next_y, next_x, cur.depth + 1, cur.pass });
					visited[next_y][next_x][0] = true;
				}
				else if (!cur.pass && map[next_y][next_x] == '1') {
					q.push_back(Position{ next_y, next_x, cur.depth + 1, true});
					visited[next_y][next_x][1] = true;
				}
			}
		}
	}
	q.clear();
	return -1;
}
int main() {
	std::ios_base::sync_with_stdio(false);
	char a;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> a;
			map[i][j] = a;
		}
	}

	int result = bfs();
	cout << result;

	return 0;
}