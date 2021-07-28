#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


struct Dir{
	int y;
	int x;
};
int N, M, T;
int X, D, K;
vector<int> board[51];
vector<Dir> temp;
bool visited[51][51];
int idx = 1;
int cnt = 0;
Dir dirs[4] = {{ 0,-1 }, { 0,1 }, { -1,0 }, { 1,0 }};

void avgBoard() {
	int total = 0;
	double avg = 0;
	for (int i = 0; i < temp.size(); i++) {
		total += board[temp[i].y][temp[i].x];
	}
	avg = total / (temp.size() * 1.0);
	for (int i = 0; i < temp.size(); i++) {
		if (avg > board[temp[i].y][temp[i].x])
			board[temp[i].y][temp[i].x]++;
		else if (avg < board[temp[i].y][temp[i].x])
			board[temp[i].y][temp[i].x]--;
	}
}
void dfs(int y, int x) {
	if (visited[y][x] )
		return;
	int cur = board[y][x];
	visited[y][x] = true;
	board[y][x] = 9999;
	cnt++;
	for (int i = 0; i < 4; i++) {
		Dir next = { y + dirs[i].y, x + dirs[i].x};
		if (next.x == -1)
			next.x = M - 1;
		else if (next.x == M)
			next.x = 0;
		if (next.y > 0 && next.y <= N && next.x >= 0 && next.x < M 
			&& !visited[next.y][next.x] && cur == board[next.y][next.x] ) {
			dfs(next.y, next.x);
		} 
	}
	return;
}

void init() {
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			visited[i][j] = false;
		}
	}
	temp.clear();
}

int compareBoard() {
	int diffCnt = 0;
	init();
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			if (!visited[i][j] && board[i][j] != 9999) {
				cnt = 0;
				int cur = board[i][j];
				diffCnt++;
				dfs(i, j);
				if (cnt == 1) {
					board[i][j] = cur;
					temp.push_back({ i,j });
					diffCnt--;
				}
			}
		}
	}
	return diffCnt;
}
void print() {
	int total = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			if (board[i][j] != 9999)
				total += board[i][j];
		}
	}
	cout << total << "\n";
}
void rotateBoard() {
	for (int i = X; i <= N; i += X) {
		if (D == 1)
			rotate(board[i].begin(), board[i].begin() + K, board[i].end());
		else
			rotate(board[i].rbegin(), board[i].rbegin() + K, board[i].rend());
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M >> T;
	for (int i = 1; i <= N; i++) { 
		for (int j = 1; j <= M; j++) {
			int t;
			cin >> t;
			board[i].push_back(t);
		}
	}
	for (int i = 0; i < T; i++) {
		cin >> X >> D >> K;
		// 회전
		rotateBoard();
		int diffCnt = compareBoard();
		// 평균 및 합산
		if ( diffCnt == 0 ) 
			avgBoard();
	}
	print();
	return 0;
}
