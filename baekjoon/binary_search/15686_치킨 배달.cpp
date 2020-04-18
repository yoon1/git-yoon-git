#include <iostream>
#include <limits.h>
#include <algorithm>
#include <vector>

using namespace std;
vector<pair<int, int>> house;
vector<pair<int, int>> chicken;

int result = INT_MAX;
int N, M;

int calcDistance(vector<pair<int, int>> t_chicken) {	
	int total = 0;
	for (int i = 0; i < house.size(); i++) {
		int distance = INT_MAX;
		for (int j = 0; j < t_chicken.size(); j++) {
			distance = min(distance,
				abs(t_chicken[j].first - house[i].first) + abs(t_chicken[j].second - house[i].second));
		}
		total += distance;
	}
	return total;
}

void dfs(int idx, vector<pair<int, int>> t_chicken) {
	if (t_chicken.size() == M) {
		result = min(calcDistance(t_chicken), result);
		return;
	}
	
	for (int start = idx; start < chicken.size(); start++) {
		t_chicken.push_back(chicken[start]);
		dfs(start + 1, t_chicken);
		t_chicken.pop_back();
	}
}
int main() {
	int t;
	cin >> N >> M;
	vector<pair<int, int>> t_chicken;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> t;
			if ( t == 1)
				house.push_back(make_pair(i,j));
			if ( t == 2)
				chicken.push_back(make_pair(i, j));
		}
	}
	dfs(0, t_chicken);

	cout << result << endl;
	return 0;
}