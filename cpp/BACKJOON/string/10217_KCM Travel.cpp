#include <iostream>
#include <vector>
#define MAX 101

using namespace std;

struct airport {
	int dst; // destination
	int cost;
	int time;
};

int T, N, M, K;
int main() {
	int T, N, M, K;
	cin >> T;
	for (int testCase = 0; testCase < T; testCase++) {
		cin >> N >> M >> K;
		vector<airport> a[MAX];
		for (int k = 0; k < K; k++) {
			int u, v, c, d;
			cin >> u >> v >> c >> d;
			a[u].push_back({ v,c,d });
		}
	}
	return 0;
}