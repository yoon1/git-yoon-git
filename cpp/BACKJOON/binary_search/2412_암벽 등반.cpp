#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>

using namespace std;

typedef struct dPos {
	int x;
	int y;
	int depth;
}DPos;
int N, T, maxValue;
vector<int> v[50001];
queue<DPos> q;
set<pair<int, int>> s;

void bfs() {
	int result = -1;
	while (!q.empty()) {
		DPos cur = q.front();
		q.pop();
		if (cur.y == T) {
			result = cur.depth;
			break;
		}
		for (int x = cur.x-2 < 0 ? 0 : cur.x-2 ; x <= cur.x+2; x++) {
			if (v[x].empty()) continue;
			vector<int>::iterator low = lower_bound(v[x].begin(), v[x].end(), cur.y-2);// xÁÂÇ¥
			for (vector<int>::iterator it = low; it != v[x].end() && *it <= cur.y+2 ; it++) {
				if ( s.find(make_pair(x, *it)) == s.end()){
					s.insert(make_pair(x, *it));
					q.push({ x, *it, cur.depth + 1 });
				}
			}
		}
	}
	cout << result << "\n";
	return;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> T;
	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		maxValue = max(maxValue, x);
		v[x].push_back(y);
	}


	// Á¤·Ä
	for (int i = 0; i <= maxValue; i++){
		if (!v[i].empty())
			sort(v[i].begin(), v[i].end());  // sorting
	}
	q.push({0,0,0});
	bfs();
	return 0;
}