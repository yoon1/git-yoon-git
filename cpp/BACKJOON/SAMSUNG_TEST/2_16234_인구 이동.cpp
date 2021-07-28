#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, L, R;
int map[50][50]; // map
bool visited[50][50] = { false };

// �����¿�
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

	// ������ ����� ���� �α��� + ������ �̷�� �ִ� ĭ�� ����(���ǻ� �Ҽ��� ����)
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
	// �Է�
	cin >> N >> L >> R;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j]; // �α� �Է�
		}
	}

	int count = 0;
	// �� ������ �α� ���̰� L�� �̻�, R�� ����. =>  ���漱�� ����
	while (true) {
		int move_flag = false;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				visited[i][j] = false;

		// �α� �̵�
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (visited[i][j]) continue;
				int cur = map[i][j];
				if (bfs(i, j))
					move_flag = true;
			}
		}
		// ���漱 ����
		//�α� �̵��� ��������? ����
		if (!move_flag) {
			break;
		}
		count++;
	}
	cout << count;
	return 0;
}

