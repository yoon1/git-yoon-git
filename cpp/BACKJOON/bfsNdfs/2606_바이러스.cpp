#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>

#define MAX 101

using namespace std;

bool visited[MAX][MAX] = { false };
int arr[MAX][MAX] = { 0 };
queue<pair<int, int>> q;

pair<int, int> dir[4] = { make_pair(0,1),make_pair(1,0),make_pair(0,-1),make_pair(-1,0)};
int N, M;

void bfs(int y, int x, int depth) {
	if (y == N && x == M) cout << depth;
	if (visited[y][x]) return;
	visited[y][x] = true;
	while(!q.empty()) {
		for (int i = 0; i < 4; i++) {
			if (y + dir[i].first > 0 && y + dir[i].first <= N
				&& x + dir[i].second > 0 && x + dir[i].second <= N
				&& arr[y + dir[i].first][x + dir[i].second == 1]
				&& !visited[y + dir[i].first][x + dir[i].second]
				) {
				q.push(pair<int, int>(y + dir[x].first, x + dir[y].second));
			}
			
		}
		pair<int, int> temp = q.front();
		q.pop();
		bfs(temp.first, temp.second, depth++);
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	string str;
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		cin >> str;
		str = " " + str;
		for (int j = 1; j <= M; j++) {
			arr[i][j] = (int)(str[j] - '0');
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	
	q.push(pair<int, int>(1, 1));
	bfs(1,1,0);
	
	return 0;

}
