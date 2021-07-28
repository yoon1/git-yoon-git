#include <iostream>
#include <algorithm>
#include <deque>
#include <string>
#include <vector>

using namespace std;

int main() {
	int testCase, N;
	scanf("%d", &testCase);
	for (int t = 0; t < testCase; t++) {
		scanf("%d", &N);
		deque<long long> dq;
		for (int i = 0; i < N; i++) {
			char spcae;
			scanf("%c", &spcae);
			char op;
			long long num;
			scanf("%c %lld", &op, &num);
			if (op == 'I') {
				dq.push_back(num);
				sort(dq.begin(), dq.end());
			}
			else if (!dq.empty()) {
				if (num == -1)
					dq.pop_front();
				else
					dq.pop_back();
			}
		}
		if (dq.empty()) {
			printf("EMPTY\n");
		}
		else {
			printf("%lld %lld\n", dq.back(), dq.front());
		}
	}
}