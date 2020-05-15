#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
int N, M;
vector<int> v;
set<vector<int>> s;
bool visited[9];
void dfs(int start, vector<int> t) {
	if (t.size() == M) {
 		s.insert(t);
		return;
	}
	for (int i = start; i < v.size(); i++) {
		if (visited[i]) continue;
		visited[i] = true;
		t.push_back(v[i]);
		dfs(i, t);
		t.pop_back();
		visited[i] = false;
	}
}
int main() {
	cin >> N >> M;
	vector<int> vt;
	for (int i = 0; i < N; i++) {
		int t;
		cin >> t;
		v.push_back(t);
	}
	sort(v.begin(), v.end());
	dfs(0, vt);

	for (auto k : s) {
		for (auto t : k) {
			cout << t << " ";
		}
		cout << "\n";
	}
	return 0;
}