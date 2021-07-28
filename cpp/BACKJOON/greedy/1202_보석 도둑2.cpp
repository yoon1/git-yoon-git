#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>

using namespace std;

int N, K;

int main() {
	//cin >> N >> K;
	scanf("%d %d", &N, &K);
	priority_queue<pair<int, int>> pq;

	for (int i = 0; i < N; i++) {
		int a, b; 
		scanf("%d %d", &a, &b);
		pq.push({ b,a });
	}

	multiset<int> bags;

	// °¡¹æ
	for (int i = 0; i < K; i++) {
		long long w; scanf("%d", &w);
		bags.insert(w);
	}

	long long totVal = 0;

	while (!pq.empty()) {
		int cost = pq.top().first;
		int pay = pq.top().second;
		pq.pop();
		auto it = bags.lower_bound(pay);
		if (it == bags.end())
			continue;
		bags.erase(it);
		totVal += cost;
	}

	cout << totVal;

	return 0;
}