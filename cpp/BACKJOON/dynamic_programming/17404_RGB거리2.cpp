#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;

int rgb[1001][3];
int dp[1001][3];
int N;
int main() {
	cin >> N;
	int result = 987654321;
	for(int i = 1; i <= N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> rgb[i][j];
		}
	}
	for (int k = 0; k <= 2; k++) {
		for (int i = 0; i <= 2; i++) {
			if (i == k)
				dp[1][i] = rgb[1][i];
			else
				dp[1][i] = 987654321;
		}
		for (int i = 2; i <= N; i++) {
			dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + rgb[i][0];
			dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + rgb[i][1];
			dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + rgb[i][2];
		}

		for (int i = 0; i <= 2; i++) {
			if (i == k) continue;
			result = min(result , dp[N][i]);
		}
	}
	cout << result << endl;
	return 0;
}