#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
	stack<int> s;
	vector<vector<int>> v = { {1, 2, 3}, {4, 5}, {5, 6}, {7}, {}, {}, {}, {} };
	bool isVisited[8] = { false, };

	s.push(0);
	cout << "push : " << 0 << endl;
	s.pop();
	isVisited[0] = true;
	cout << "visited : " << 0 << endl;
	for (int i = v[0].size() - 1; i >= 0; i--) {
		s.push(v[0][i]);
		cout << "push : " << v[0][i] << endl;
	}

	while (!s.empty()) {
		int cur = s.top();
		s.pop();
		isVisited[cur] = true;
		cout << "visited : " << cur << endl;
		for (int i = v[cur].size() - 1; i >= 0; i--) {
			if (!isVisited[v[cur][i]]) {
				s.push(v[cur][i]);
				cout << "push " << v[cur][i] << endl;
			}
		}
	}
}