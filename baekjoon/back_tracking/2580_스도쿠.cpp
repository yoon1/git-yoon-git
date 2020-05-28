#include <iostream>
//#include <fstream>
#include <vector>

using namespace std;

bool flag = false;
int map[9][9];
vector<pair<int, int>> v;

void print() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
}
bool isPromising(int y, int x) {
	int n = map[y][x];
	for (int i = 0; i < 9; i++) {
		if (i == x) continue;
		if (n == map[y][i]) return false;
	}
	for (int i = 0; i < 9; i++) {
		if (i == y) continue;
		if (n == map[i][x]) return false;
	}
	pair<int, int> pos = { y / 3 , x / 3 };
	for (int i = pos.first * 3; i < pos.first * 3 + 3; i++) {
		for (int j = pos.second * 3 ; j < pos.second * 3 + 3; j++) {
			if (i == y && j == x) continue;
			if (n == map[i][j] ) return false;
		}
	}
	return true;
}
void dfs(int n) {
	if (flag)
		return;

	if (n >= v.size()) {
		print();
		flag = true;
		return;
	}

	for (int i = 1; i  <= 9; i++) {
		map[v[n].first][v[n].second] = i;
		if (isPromising(v[n].first, v[n].second)) {
			dfs(n + 1);
		}
		map[v[n].first][v[n].second] = 0;
	}
}
int main() {
	//freopen("test.txt", "r", stdin);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0)
				v.push_back({ i, j });
		}
	}
	dfs(0);
	return 0;
}