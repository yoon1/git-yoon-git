#include <iostream>
#include <algorithm>

using namespace std;

int dp[1001][1001];
int N, K;

int main() {
	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			for (int k = 1; k <= K; k++) {
				dp[i][j] = min(dp[i-1][j], dp[i-1][j-1]) + 
			}
		}

	}
	return 0;
}
