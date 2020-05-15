// N개의 자연수 중에서 M개를 고르는 수열
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int N, M;

vector<int> v;
map<int, int> m;

void dfs(int start, vector<int> t) {
	if (t.size() == M) {
		for (int i = 0; i < t.size(); i++) {
			cout << t[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = start; i < v.size(); i++) {
		if (m[v[i]])
		{
			m[v[i]]--;
			t.push_back(v[i]);
			dfs(start, t);
			t.pop_back();
			m[v[i]]++;

		}
	}
}

int main() {
	cin >> N >> M;
	vector<int> vt;
	for (int i = 0; i < N; i++) {
		int t;
		cin >> t;
		if (!m.count(t)) {
			m[t] = 1;
			v.push_back(t);
		}
		else {
			m[t]++;
		}
	}
	sort(v.begin(), v.end());

	dfs(0, vt);
	return 0;
}
