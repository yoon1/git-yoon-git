#include <iostream>
#include <vector>
#include <set>

using namespace std;

int parent[201];

int getParent(int x) {
	if (parent[x] == x) return x;
	return parent[x] = getParent(parent[x]);
}
void unionParent(int a, int b){
	a = getParent(a);
	b = getParent(b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}
int solution(int n, vector<vector<int>> computers) {
	for (int i = 0; i <= n; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < computers.size(); i++) {
		for (int j = 0; j < computers[i].size(); j++) {
			if ( i != j && computers[i][j] == 1)
				unionParent(i, j);
		}
	}
	set<int> s;
	for (int i = 0; i < n; i++)
		s.insert(getParent(parent[i]));
	return s.size();
}