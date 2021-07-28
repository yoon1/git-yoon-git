#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#define WHITE 0 
#define RED 1
#define BLUE 2

using namespace std;

struct target {
	int y, x;
	int d;
};

int N, K;
int board[13][13];
target targets[11];
vector<int> tv[13][13];

// 제자리, 오, 왼, 위, 아래
int dy[5] = { 0, 0, 0, -1, 1 };
int dx[5] = { 0, 1, -1, 0, 0 };

bool isWallet(int y, int x) {
	if (!(y > 0 && y <= N && x > 0 && x <= N)) return true;
	if (board[y][x] == BLUE) return true;
	return false;
}
bool go() {
	for (int num = 1; num <= K; num++) {
		target cur = targets[num]; // 현재 말 가져오기
		// next point 설정
		int ny = cur.y + dy[cur.d]; 
		int nx = cur.x + dx[cur.d];
		int nd = cur.d;

		// next 검증(보드판 밖이나 파란색(벽)이 있는지 확인)
		if ( isWallet(ny, nx)){
			nd = nd % 2 == 0 ? nd - 1 : nd + 1;
			ny = cur.y + dy[nd];
			nx = cur.x + dx[nd];
			targets[num].d = nd;
			if (isWallet(ny, nx))  
				continue;
		}

		// white, red에 대한 처리
		vector<int>::iterator it = find(tv[cur.y][cur.x].begin(), tv[cur.y][cur.x].end(), num); // index검색
		vector<int> temp(it, tv[cur.y][cur.x].end()); 
		if (tv[cur.y][cur.x].size() == temp.size())
			tv[cur.y][cur.x].clear(); // 전부 다
		else
			tv[cur.y][cur.x] = vector<int>(tv[cur.y][cur.x].begin(), it); // 앞부분만 남겨놓고

		if (board[ny][nx] == RED) {
				// 뒤집고
				reverse(temp.begin(), temp.end());
		}

		//합치기
		for (int i = 0; i < temp.size(); i++) {
			tv[ny][nx].push_back(temp[i]);
			targets[temp[i]].y = ny;
			targets[temp[i]].x = nx;
		}
		if ( tv[ny][nx].size() >= 4) 
			return true;
	}
	return false;
}

int main() {
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> board[i][j]; // 0은 흰색, 1은 빨간색, 2는 파란색
		}
	}
	int y, x, d;
	for (int i = 1; i <= K; i++) {
		cin >> y >> x >> d;
		targets[i] = { y,x,d }; // y, x, 좌표
		tv[y][x].push_back(i); //index를 넣음!!
	}

	int turn = 1;
	while (1) {
		if (turn > 1000) {
			cout << "-1";
			return 0;
		}
		if (go()) {
			break;
		}
		turn++;
	}
	cout << turn;
	return 0;
}