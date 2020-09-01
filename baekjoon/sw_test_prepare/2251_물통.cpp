#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#define a 0
#define b 1
#define c 2
using namespace std;

vector <int> bucket_size(3); // 3개 a,b,c
queue<vector<int>> q;
set<pair<int, int>> s; // b, c
set<int> answer;
vector<int> pour(vector<int> bucket, int in, int out) {// in : 물을 받는 쪽, out : 물을 비우는 쪽
	int water = bucket_size[in] - bucket[in];
	if (bucket[out] > water) {
		bucket[out] = bucket[out] - water;
		bucket[in] = bucket[in] + water;
	}
	else {
		bucket[in] += bucket[out];
		bucket[out] = 0;
	}
	return bucket;
}
void addSet(vector<int> next) {
	if (s.find({ next[b], next[c] }) == s.end()) {
		s.insert({ next[b], next[c] });
		q.push(next);
	}
}
int main() {
	cin >> bucket_size[a] >> bucket_size[b] >> bucket_size[c];
	q.push({ 0,0,bucket_size[c] }); // 비어, 비어, full
	while (!q.empty()) {
		vector<int> cur = q.front(); // 현재 값 가져오기
		q.pop();
		if (cur[a] == 0)
			answer.insert(cur[c]);
		vector<int> next(3);
		// A <- B
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (i == j) continue;
				next = pour(cur, i, j); addSet(next);
			}
		}
	}
	for (int water : answer) cout << water << " ";
	return 0;
}