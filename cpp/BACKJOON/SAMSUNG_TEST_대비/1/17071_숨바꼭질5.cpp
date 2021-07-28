#include <iostream>
#include <set>
#include <queue>

using namespace std;

int memo[1001];
queue<pair<int, int>> q; // 수빈이 좌표, 동생의 좌표(memo)
set<pair<int, int>> s;
int N, K; // 수빈이, 동생

void move(int move, int subin_move) { // 수비니, 동생
	if (!(subin_move >= 0 && subin_move <= 500000)) return;
	if (memo[move + 1] > 500000) return;
	if (s.find({ subin_move, move % 2 }) == s.end()) {
		s.insert({ subin_move, move % 2 });
		q.push(make_pair(subin_move, move + 1));
	}
}
int bfs() {
	while (!q.empty()) {
		int subin = q.front().first;
		int sister = q.front().second;
		q.pop();
		cout << subin << "," << sister << "," << memo[sister] << endl;
		if (subin == memo[sister]) 
			return sister;
		move(sister, subin + 1);
		move(sister, subin - 1);
		move(sister, subin * 2);
	}
	return -1;
}

int main() {
	cin >> N >> K;
	// memo
	for (int i = 0; i < 1001; i++) {
		memo[i] = 987654321;
	}
	memo[0] = K;
	for (int i = 1; ; i++) {
		int t = memo[i - 1] + i;
		if ( t > 500000) break;
		memo[i] = t; 
	}

/*	for (int i = 0; i < 10; i++){
		cout << memo[i] << endl;
	} */
	q.push({ N,0 });
	cout << bfs() << "\n";
	return 0;
}

// 6, 4, 10 --> 18
// 20 --> 2