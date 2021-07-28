#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 20

using namespace std;

int b[MAX][MAX];
int board[MAX][MAX];
int N;
int answer = 0;

void copy() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			b[i][j] = board[i][j];
	}
}
int move(vector<int> v, int b[MAX][MAX]) {
	int result = 0;
	for (int n = 0; n < v.size(); n++) { // 5번
		int d = v[n];
		for (int y = 0; y < N; y++) { // 좌,우,상,하
			vector<int> key;
			for (int x = 0; x < N; x++) {
				int cur = d < 2 ? b[y][x] : b[x][y];
				if (cur != 0) {
					key.push_back(cur);
				}
			}
			if (d == 1 || d == 3)
				reverse(key.begin(), key.end());
			vector<int> nextkey;
			for (int p = 0; p < key.size(); p++) {
				if (p + 1 < key.size() 
					&& key[p] == key[p + 1])
				{
					nextkey.push_back(key[p] * 2);
					p++;
				}
				else
					nextkey.push_back(key[p]);
			}
			for (int p = nextkey.size(); p < N; p++) {
				nextkey.push_back(0);
			}
			if (d == 1 || d == 3)
				reverse(nextkey.begin(), nextkey.end());
			for (int x = 0; x < N; x++) {
				(d < 2 ? b[y][x] : b[x][y]) = nextkey[x];
				result = max(result, nextkey[x]);
			}
		}
	}
	return result;
}


void dfs(vector<int> t) { // 탐색
	if (t.size() == 5) { // t.size가 5개가 되면? // 방향!
		copy(); //b를 이용해서 move!! (board는 계속 갖고 있음)
		answer = max(answer, move(t, b));
		return;
	}
	for (int i = 0; i < 4; i++) { // 4방향
		t.push_back(i);
		dfs(t);
		t.pop_back();
	}
}
int main() {
	cin >> N;
	// 입력
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}
	vector<int> t;
	dfs(t);
	cout << answer << endl;
}