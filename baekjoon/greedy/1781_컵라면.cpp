#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

bool cmpV(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first) return a.second > b.second;
	return a.first < b.first;
}

vector<pair<int, int>> v;
priority_queue <int, vector<int>, greater<int> > pq;

int main() {
	int N;
	int total = 0;
	
	scanf_s("%d", &N);
	for (int i = 0; i < N; i++) {
		pair<int, int> deadlineAndScore;
		scanf_s("%d %d", &deadlineAndScore.first, &deadlineAndScore.second);
		v.push_back(deadlineAndScore);
	}

	sort(v.begin(), v.end(), cmpV);
	
	for (int i = 0; i < v.size(); i++) {
		int deadline = v[i].first;
		int food = v[i].second;
		pq.push(food);
		while (deadline < pq.size()) {
			pq.pop();
		}
	}

	while (!pq.empty()) {
		total += pq.top();
		pq.pop();
	}
	printf("%d", total);

	return 0;
}