#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

#define INF 98765421

using namespace std;

struct pos {
	int y, x;
	bool operator < (const pos &rhs) const {
		bool b = y < rhs.y || (y == rhs.y && x < rhs.x);
		return (b);
	}
};
int N, M;
char board[21][21];

int dy[4] = {1,0,0,-1};
int dx[4] = {0,1,-1,0};
int min_cnt = INF;

vector<pos> coins;

map<pair<pos, pos>, int> m;

void dfs(pos coin1, pos coin2, int move_cnt) {
	bool flag1 = false, flag2 = false;
	if (!(coin1.y >= 0 && coin1.y < N && coin1.x >= 0 && coin1.x < M)) flag1 = true;
	if (!(coin2.y >= 0 && coin2.y < N && coin2.x >= 0 && coin2.x < M)) flag2 = true;
	if (flag1 && flag2 ) return;
	if (flag1 || flag2) {
		min_cnt = min(min_cnt, move_cnt);
		return;
	}
	if (move_cnt >= 10) return;

	for(int i=0; i < 4; i++){
		pos next_coin1 = { coin1.y + dy[i] , coin1.x + dx[i] };
		pos next_coin2 = { coin2.y + dy[i] , coin2.x + dx[i] };

		// º®
		if ((next_coin1.y >= 0 && next_coin1.y < N && next_coin1.x >= 0 && next_coin1.x < M) && board[next_coin1.y][next_coin1.x] == '#')
			next_coin1 = coin1;
		if ((next_coin2.y >= 0 && next_coin2.y < N && next_coin2.x >= 0 && next_coin2.x < M) && board[next_coin2.y][next_coin2.x] == '#')
			next_coin2 = coin2;

		if (m.find({ next_coin1, next_coin2 }) == m.end()
			|| m[{next_coin1, next_coin2}] > move_cnt + 1 ) {
			m[{next_coin1, next_coin2}] = move_cnt + 1;
			dfs(next_coin1, next_coin2, move_cnt + 1);
		}
	}
}

int main() {
	cin >> N >> M;
	
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			scanf(" %c", &board[y][x]);
			if (board[y][x] == 'o') {
				coins.push_back({ y, x });
				board[y][x] = '.';
			}
		}
	}

	dfs(coins[0], coins[1],0);

	cout << ((min_cnt > 10) ? -1 : min_cnt) << endl;
	return 0;
}



