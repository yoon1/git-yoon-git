#include <iostream>
#include <queue>
#define MAX 100

using namespace std;

int N, M;
pair<int, int> dir[4] = {make_pair(0,1),make_pair(1,0),make_pair(0,-1),make_pair(-1,0)};
queue<pair<int, int>> q;
int visited[MAX][MAX];
char arr[MAX][MAX];

void bfs(int y, int x) {
	q.push(make_pair(y, x));
	visited[y][x] = 1;
	while (!q.empty()) {
		pair<int, int> temp = q.front();
		q.pop();

		if (temp.first == N-1 && temp.second == M-1) {
			cout << visited[N-1][M-1];
			return;
		}

		for (int i = 0; i < 4; i++) {
			int py = temp.first + dir[i].first;
			int px = temp.second + dir[i].second;
			if (px >= 0 && px < M && py >= 0 && py < N 
				&& visited[py][px] == 0 && arr[py][px] == '1') {
				visited[py][px] = visited[temp.first][temp.second] + 1;

				q.push(make_pair(py, px));
			}
		}
	}
}


int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	bfs(0, 0);
	return 0;
}