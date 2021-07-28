#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
int N, M;
vector<int> v;
set<vector<int>> s;
bool visited[9];
void dfs(vector<int> t) {
	if (t.size() == M) {
		s.insert(t);
		return;
	}
	for (int i = 0; i < v.size(); i++) {
		if (!t.empty() && t.back() > v[i])  continue;
		t.push_back(v[i]);
		dfs(t);
		t.pop_back();
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
	dfs(vt);

	for (auto k : s) {
		for (auto t : k) {
			cout << t << " ";
		}
		cout << "\n";
	}
	return 0;
}