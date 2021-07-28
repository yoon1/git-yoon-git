#include <set>
#include <memory.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#define MAX 100

using namespace std;

int a[MAX][MAX] = { 0 };
int zero[MAX][MAX] = { 0 };
int row, col;
int r, c, k;
vector<vector<int>> v;

struct sortPairSecond {
	bool operator()(const pair<int, int> &lhs, const pair<int, int> &rhs){
		if (lhs.second == rhs.second) return lhs.first < rhs.first;
		return lhs.second < rhs.second;
	}
};

void print() {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}
void copyArray() {
	int cur_row = 0;
	int cur_col = 0;
	if (row >= col) {// R >= C:
		memcpy(a, zero, sizeof(a)); // 0으로 초기화
		for (int i = 0; i < v.size() && i < MAX; i++) {
			for (int j = 0; j < v[i].size() && j < MAX; j++) {
				a[i][j] = v[i][j];
				cur_col = max(j + 1, cur_col);
			}
			cur_row = max(i + 1, cur_row);
		}
		row = cur_row;
		col = cur_col;
	}
	else { //R < C;
		memcpy(a, zero, sizeof(a)); // 0으로 초기화
		for (int i = 0; i < v.size() && i < MAX; i++) {
			for (int j = 0; j < v[i].size() && j < MAX; j++) {
				a[j][i] = v[i][j];
				cur_row = max(j + 1, cur_row);
			}
			cur_col = max(i + 1, cur_col);
		}
		row = cur_row;
		col = cur_col;
	}
}

void changeArray() {
	if (row >= col) {// R >= C:
		for (int i = 0; i < row; i++) {
			vector<int> t;
			map<int, int> m;
			
			for (int j = 0; j < col; j++) {
				if ( a[i][j] != 0) 
					m[a[i][j]]++;
			}
			set<pair<int, int>, sortPairSecond> s;
			for (auto it = m.begin(); it != m.end(); it++) {
				s.insert(*it);
			}
			for (auto it = s.begin(); it != s.end(); it++) {
				t.push_back(it->first);
				t.push_back(it->second);
			}
			int size = t.size();
			v.push_back(t);
		}
	}
	else { //R < C;
		for (int i = 0; i < col; i++) {
			vector<int> t;
			map<int, int> m;
			for (int j = 0; j < row; j++) { // 00 01 02 ... ==> 10 20 30.. 
				if (a[j][i] != 0)
					m[a[j][i]]++;
			}
			set<pair<int, int>, sortPairSecond> s;
			for (auto it = m.begin(); it != m.end(); it++) {
				s.insert(*it);
			}
			for (auto it = s.begin(); it != s.end(); it++) {
				t.push_back(it->first);
				t.push_back(it->second);
			}
			int size = t.size();
			v.push_back(t);
		}
	}
}

int main() {
	cin >> r >> c >> k; // a[r][c] == k 인 경우를 찾아라
	int result = 0;
	row = 3, col = 3;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> a[i][j];
		}
	}
	while (a[r - 1][c - 1] != k) {
		if (result > 100) {
			cout << "-1";
			return 0;
		}
		v.clear();
		changeArray();
		copyArray();
		result++;
	}
	cout << result;
	return 0;
}