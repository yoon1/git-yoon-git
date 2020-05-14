// 1부터 N까지 자연수 중에서 M개를 고른 수열
// 중복 가능
// 비내림차순 (같거나 오름차순)
// 중복 가능 조합

#include <iostream>
#include <vector>
using namespace std;

int N, M;

void dfs(vector<int> v) {
	if (v.size() == M) {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 1; i <= N; i++) {
		if (!v.empty() && v.back() > i)
			continue;
		v.push_back(i);
		dfs(v);
		v.pop_back();
	}
}

int main() {
	vector<int> v;
	cin >> N >> M;
	dfs(v);
	return 0;
}