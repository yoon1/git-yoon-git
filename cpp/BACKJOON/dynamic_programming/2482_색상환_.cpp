#include <iostream>

using namespace std;

int MOD = 1000000003;
int N, K;
int dp[1001][1001]; // N개 중 K개 뽑는 경우의 수

int main() {
	cin >> N >> K;
	for (int i = 0; i <= N; i++) {
		dp[i][0] = 1; // 0개 -> 1가지
		dp[i][1] = i; // 1개 -> i가지
	}

	for (int i = 2; i <= N; i++)
		for (int j = 2; j <= K; j++)
			dp[i][j] = (dp[i - 2][j - 1] + dp[i - 1][j]) % MOD;

	cout << (dp[N - 3][K - 1] + dp[N - 1][K]) % MOD;
	return 0;
}