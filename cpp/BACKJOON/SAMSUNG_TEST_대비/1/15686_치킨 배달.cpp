#include <stdio.h>
#include <vector>
#include <algorithm>
#define MAX 50
#define INF 2e8

using namespace std;

vector<pair<int, int>> chicken;
vector<pair<int, int>> home;
int N, M;
int MM;
int result;

int operation(vector<pair<int, int>> t_chicken) {
	int sum = 0;
	for (int i = 0; i < home.size(); i++) {
		int chicken_distance = INF;
		pair<int, int> h = home[i];
		for (int j = 0; j < t_chicken.size(); j++) {
			pair<int, int> t = t_chicken[j];
			chicken_distance = min(chicken_distance, abs(h.first - t.first) + abs(h.second - t.second));
		}
		sum += chicken_distance;
	}
	return sum;
}

void go(vector<pair<int, int>> t_chicken, int idx) {
	if (t_chicken.size() == MM) {
		result = min(result, operation(t_chicken)); // 작으면 연산
		return;
	}
	for (int i = idx; i < chicken.size(); i++) {
		t_chicken.push_back(chicken[i]);
		go(t_chicken, i+1);
		t_chicken.pop_back();
	}
	return;
}
int main() {
	scanf("%d %d", &N, &M);
	result = INF;

	vector<pair<int, int>> t_chicken;
	int t;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf(" %d", &t);
			if (t == 2)
				chicken.push_back(make_pair(i, j));
			if (t == 1)
				home.push_back(make_pair(i, j));
		}
	}
	int size = chicken.size();
	MM = min(M, size);
	go(t_chicken, 0);
	printf("%d", result);
	return 0;
}