#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
	int N;
	int maxValue = 0;
	int cnt[10001] = { 0 }; // 빈도수 => 누적값

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int t;
		scanf("%d", &t);
		cnt[t]++; // counting
		maxValue = max(t, maxValue);
	}

	for (int i = 1; i <= maxValue; i++) {
		for (int j = 0; j < cnt[i]; j++) {
			printf("%d\n", i);
		}
	}
	return 0;


}