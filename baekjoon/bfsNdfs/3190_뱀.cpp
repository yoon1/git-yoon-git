#include <iostream>
#include <vector>
#include <memory.h>
#include <deque>

using namespace std;

int N, K, L;
int m[101][101];
vector<pair<int, int>> dir = { make_pair(0,1), make_pair(1,0), make_pair(0,-1), make_pair(-1,0) };
deque<pair<int, int>> snake;
deque<pair<int, char>> v_dir;

int sec = 0;

bool isCrush(int y, int x) {
	if (m[y][x] == 2)
		return true;
	if (y > 0 && x > 0 && y <= N && x <= N)
		return false;
	return true;
}

void moveSnake() {
	int curDir = 0;
	while (!snake.empty()) {
		if (!v_dir.empty() && sec == v_dir.front().first) {
			if (v_dir.front().second == 'L') 
				curDir = (curDir - 1 + 4) % 4;
			else
				curDir = (curDir + 1 + 4) % 4;
			v_dir.pop_front();
		}
		pair<int, int> nextPos;
		nextPos.first = snake.front().first + dir[curDir].first;
		nextPos.second = snake.front().second + dir[curDir].second;
		sec++;
		if (isCrush(nextPos.first, nextPos.second)) // 충돌 
			return;
		if (m[nextPos.first][nextPos.second] == 0){
			m[snake.back().first][snake.back().second] = 0;
			snake.pop_back();
		}
		m[nextPos.first][nextPos.second] = 2;
		snake.push_front(nextPos);
	}
}
int main() {
	memset(m, 0, sizeof(m));
	cin >> N >> K;
	m[1][1] = 2; // snake;
	snake.push_front(make_pair(1, 1)); 
	for (int i = 0; i < K; i++) {
		pair<int, int> t;
		cin >> t.first >> t.second;
		m[t.first][t.second] = 1; // 사과
	}
	cin >> L;
	for (int i = 0; i < L; i++) {
		pair<int, char> t;
		cin >> t.first >> t.second;
		v_dir.push_back(t);
	}
	moveSnake();
	cout << sec << endl;
	return 0;
}