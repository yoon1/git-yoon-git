#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, L, R;

typedef struct pos{
	int y;
	int x;
}Pos;

Pos dir[4] = { {0,-1},{0,1},{1,0},{-1,0} };
int map[50][50];
bool visited[50][50];
//bool moveFlag = true;
vector<Pos> v;
queue<Pos> q;

void print() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
}
void init() { // 초기화
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visited[i][j] = false;
		}
	}
}
int move() { // 이동
	int total = 0;
	while (!q.empty()) {
		Pos cur = q.front();
		total += map[cur.y][cur.x];
		q.pop();
		for (int i = 0; i < 4; i++) {
			Pos next = { cur.y + dir[i].y, cur.x + dir[i].x };
			int distance = abs(map[next.y][next.x] - map[cur.y][cur.x]);
			if (next.y >= 0 && next.y < N && next.x >= 0 && next.x < N) {
				if (!visited[next.y][next.x] &&
					distance >= L && distance <= R) {
					v.push_back(next);
					visited[next.y][next.x] = true;
					q.push(next);
				}
			}
		}
	}
	// 인구 평균
	int avg = total / v.size();
	
	// 인구 분할
	for (int i = 0; i < v.size(); i++) {
		map[v[i].y][v[i].x] = avg;
	}

	return v.size();
}

bool open() { // 국경 열기
	bool change = false;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j]) {
				int origin = map[i][j];
				v.clear();
				q.push({ i,j });
				visited[i][j] = true;
				v.push_back({ i,j });
				if ( move() != 1)
					change = true;
			}
		}
	}
	return change;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> L >> R;
	int rslt =0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	while (1) { // 국경 열기. moveFlag 가 false일 때까지 반복.
		init();
		if (!open())
			break;
//		print();
		rslt++;
	}
	cout << rslt << endl;
	return 0;
}