// 1부터 N까지 자연수 중에서 M개를 고른 수열
// 같은 수를 여러 번 골라도 됨.
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
	for(int idx = 1 ; idx <= N; idx++) {
		v.push_back(idx);
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