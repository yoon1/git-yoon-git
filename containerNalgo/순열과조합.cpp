#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#define SELECT_NUM 3
#define TOTAL_NUM 5

using namespace std;

// ### next_permutation 함수 : 조합
int main() {
	vector<int> t(TOTAL_NUM - SELECT_NUM, 0);

	vector<string> words = { "APPLE","BANANA","CHERRY","GRAPE","MELON" };

	for (int i = 0; i < SELECT_NUM; i++)
		t.push_back(1);

	cout << endl;
	int n = 1;
	do {
		vector<string> v;
		for (int i = 0; i < words.size(); i++) {
			if (t[i] == 1)
				v.push_back(words[i]);
		}
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << " ";
		}
		cout << endl;
	} while (next_permutation(t.begin(), t.end()));

	return 0;
}

// ### next_permutation 함수 : 순열
int main() {
	vector<int> v;
	for (int i = 1; i <= 3; i++) 
		v.push_back(i);

	do {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << " ";
		}
		cout << endl;
	} while (next_permutation(v.begin(), v.end()));

	return 0;
} 


// ### DFS : 조합
vector<int> v;
void dfs(int idx, vector<int> vt) {
	if (vt.size() == 3) {
		for (int i = 0; i < vt.size(); i++) {
			cout << vt[i] << " ";
		}
		cout << endl;
		return;
	}

	for (int start = idx; start < v.size(); start++) {
		vt.push_back(v[start]);
		dfs(start + 1, vt);
		vt.pop_back();
	}
}

int main() {
	for (int i = 1; i <= 5 ; i++) {
		v.push_back(i);
	}
	vector<int> vt;
	dfs(0, vt);
	return 0;
}
