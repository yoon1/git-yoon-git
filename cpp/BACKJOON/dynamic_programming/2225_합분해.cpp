#include <iostream>
#include <algorithm>
#define SIZE 200

using namespace std;

long long dp[SIZE][SIZE];

int main() {
	int N, K;
	cin >> N >> K;
	for (int i = 0; i <= K; i++) {
		for (int j = 0; j <= K; j++) {
			if (i == 0) {
				dp[i][j] = 1;
				continue;
			}
			for (int k = 0; k <= i; k++) {
				dp[i][j] += dp[k][j - 1];
			}
		}
	}

	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= K; j++) {
			cout << dp[i][j] << " ";
		}
		cout << "\n";
	}
	cout << dp[N][K];
}