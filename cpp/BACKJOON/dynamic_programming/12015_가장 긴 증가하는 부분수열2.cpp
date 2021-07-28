#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int N;
vector<int> v[1001];

int main() {
	cin >> N;
	int res_idx = 0;
	for (int i = 0; i < N; i++) {
		int t; 
		cin >> t;
		for (int j = 0; j <= N; j++) {
			if (v[j].empty() || v[j].back() < t) {
				v[j].push_back(t);
				if (v[j].size() > res_idx)
					res_idx = j;
			}
		}
	}
	
	cout << v[res_idx].size() << endl;
	for (int i = 0; i < v[res_idx].size(); i++) {
		cout << v[res_idx][i] << " ";
	}
	cout << endl;
	
	/*
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < v[j].size(); j++) {
			cout << v[i][j] << " ";
		}
		cout << "\n";
		cout << "=========================================\n";
	}
	*/
	return 0;
}