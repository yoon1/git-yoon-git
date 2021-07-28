#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct pos { int y, x; };
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,1,-1 };
int N, W;
int map[1001][1001] = { 0 };
pos car_1, car_2, dest;
int total_distance = 0;
bool visited[1001][1001];
vector<int> car_num;

void bfs(pos car) {
	queue<pair<pos, int>> q; 
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++) 
			visited[i][j] = false; // 시작점
	q.push({ { car.y, car.x }, 0 });
	visited[car.y][car.x] = true;

	while (!q.empty()) {
		pos cur = q.front().first;
		int cur_d = q.front().second;
		q.pop();
		if (cur.y == car_1.y && cur.x == car_1.x) {
			car_1 = dest;
			total_distance += cur_d;
			car_num.push_back(1);
			return;
		}
		else if (cur.y == car_2.y && cur.x == car_2.x) {
			car_2 = dest;
			total_distance += cur_d;
			car_num.push_back(2);
			return;
		}
		for (int i = 0; i < 4; i++) {
			pos next = { cur.y + dy[i], cur.x + dx[i] };
			if (!(next.y >= 0 && next.y < N && next.x >= 0 && next.x < N)) continue;
			if (visited[next.y][next.x]) continue;
			visited[next.y][next.x] = true;
			q.push({ {next.y, next.x}, cur_d + 1 });
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// 1. INPUT 
	cin >> N >> W;
	car_1 = { 0,0 }; 
	car_2 = { N - 1, N - 1 };
	// 2. 경찰차 이동
	for (int i = 0; i < W; i++) {
		cin >> dest.y >> dest.x; // 사건 발생
		dest.y--, dest.x--;
		bfs(dest);
	}
	
	cout << total_distance << endl;
	for (int i = 0; i < car_num.size(); i++) {
		cout << car_num[i] << endl;
	}

	return 0;
}