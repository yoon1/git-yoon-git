#include <iostream>
#include <memory.h>
#include <algorithm>
#define MAX 100001

using namespace std;
/* 
50 10 100 20 40 
30 50  70 10 60
*/
int dp[2][MAX + 1];
int sticker[2][MAX];

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// Test Case 입력
	int T;
	cin >> T;
	for (int testCase = 0; testCase < T; testCase++) {
		memset(dp, 0, sizeof(dp));

		// n 입력
		int N;
		cin >> N;

		// 스티커 배열 입력.
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < N; j++) {
				cin >> sticker[i][j];
			}
		}

		// dp 
		if (N >= 1) {
			dp[0][0] = sticker[0][0];
			dp[1][0] = sticker[1][0];
		}

		if (N >= 2) {
			dp[0][1] = sticker[0][1] + dp[1][0];
			dp[1][1] = sticker[1][1] + dp[0][0];
		}

		for (int i = 2; i < N; i++) {
			dp[0][i] = max(sticker[0][i] + dp[1][i - 1],
				max(sticker[0][i] + dp[0][i - 2], sticker[0][i] + dp[1][i - 2]));
			dp[1][i] = max(sticker[1][i] + dp[0][i - 1],
				max(sticker[1][i] + dp[0][i - 2], sticker[1][i] + dp[1][i - 2]));
		}

		cout << max(dp[0][N - 1], dp[1][N - 1]) << endl;
	}

	return 0;
}