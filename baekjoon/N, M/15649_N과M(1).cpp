// 1���� N������ �ڿ��� �߿��� �ߺ����� M���� �� ����.
// �ߺ��Ǵ� ���� ���� �� ��� X
// ������ �������� �����ؼ� ���.

#include <iostream>
#include <vector>

using namespace std;

int N, M;
bool visited[9];

void dfs(vector<int> v) {
	if (v.size() == M) {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 1; i <= N; i++) {
		/* 1 : iterator */
		/* 
		auto it = find(v.begin(), v.end(), i);
		if (it != v.end()) continue;
		*/
		/* 2 : visited */
		if (visited[i]) continue;
		v.push_back(i);
		visited[i] = true;
		dfs(v);
		v.pop_back();
		visited[i] = false;
	}
}

int main() {
	cin >> N >> M;
	vector<int> v;
	dfs(v);
	return 0;
}