#include <iostream>
#include <algorithm>
#define MAX 987654321

using namespace std;

int dp[1000000];
int N;
int main() {
	cin >> N;

	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;
	for (int i = 4; i <= N; i++) {
		int case1 = MAX;
		int case2 = MAX;
		int case3 = MAX;
		if (i % 3 == 0) case1 = dp[i / 3];
		if (i % 2 == 0) case2 = dp[i / 2];
		case3 = dp[i - 1];
		dp[i] = 1 + min(case1, min(case2, case3));
	}

	cout << dp[N] << endl;
	return 0;
}