#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, L, R;
int map[50][50]; // map
bool visited[50][50] = { false };

// 상하좌우
int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };

bool bfs(int y, int x) {
	vector<pair<int, int> > friends;
	queue<pair<int, int> > q;
	visited[y][x] = true;
	friends.push_back({ y,x });
	q.push({ y, x });

	int total = 0;
	while (!q.empty()) {
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();
		total += map[cy][cx];
		for (int i = 0; i < 4; i++) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (!(ny >= 0 && ny < N && nx >= 0 && nx < N)) continue;
			if (visited[ny][nx]) continue;
			int diff = abs(map[cy][cx] - map[ny][nx]);
			if (!(diff >= L && diff <= R)) continue;
			visited[ny][nx] = true;
			friends.push_back({ ny, nx });
			q.push({ ny, nx });
		}
	}

	// 연합한 나라는 연합 인구수 + 연합을 이루고 있는 칸의 갯수(편의상 소숫점 버림)
	int size = friends.size();
	if (size == 1) {
		visited[y][x] = false;
		return false;
	}
	int avg = total / size;
	for (int i = 0; i < size; i++) {
		map[friends[i].first][friends[i].second] = avg;
	}
	return true;
}
int main() {
	// 입력
	cin >> N >> L >> R;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j]; // 인구 입력
		}
	}

	int count = 0;
	// 두 나라의 인구 차이가 L명 이상, R명 이하. =>  국경선을 연다
	while (true) {
		int move_flag = false;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				visited[i][j] = false;

		// 인구 이동
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (visited[i][j]) continue;
				int cur = map[i][j];
				if (bfs(i, j))
					move_flag = true;
			}
		}
		// 국경선 닫음
		//인구 이동이 없었으면? 종료
		if (!move_flag) {
			break;
		}
		count++;
	}
	cout << count;
	return 0;
}

