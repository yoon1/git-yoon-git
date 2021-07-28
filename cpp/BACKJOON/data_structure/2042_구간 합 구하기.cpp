#include <iostream>
#include <map>

using namespace std;
long long origin[1000001]; // origin
long long acc[1000001]; // 누적
int N, M, K;

map<int, int> m;

long long sumSection(int start, int end) {
	long long ret = 0;
	// 1. acc 구간합
	long long t = start == 0 ? 0 : acc[start- 1];
	ret = acc[end] - t;

	// idx;
	for (auto it = m.lower_bound(start); it != m.end(); it++) {
		if (it->first > end) break;
		ret += (it->second);
		ret -= origin[(it->first)];
	}
	return ret;
}

int main() {
	
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 0; i < N; i++) {
		scanf("%d", &origin[i]);
		acc[i] = (i == 0) ? origin[i] : (origin[i] + acc[i - 1]);
	}

	for (int i = 0; i < M + K; i++) {
		int op, n1, n2;
		scanf("%d %d %d", &op, &n1, &n2);
		n1--; 
		switch (op) {
		case 1: // change
			m[n1] = n2;
			break;
		case 2: // print
			n2--;
			printf("%lld\n", sumSection(n1, n2));
			break;
		}
	}
	return 0;
}