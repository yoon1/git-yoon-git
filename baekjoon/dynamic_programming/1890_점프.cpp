#include <iostream>

using namespace std;

long long map[100][100];
long long dp[100][100];

int main() {
	int N;
	long long n = 0;

	cin >> N;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	dp[0][0] = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (dp[i][j] && map[i][j]) {
				n = map[i][j];
				if (j + n < N)
					dp[i][j + n] += dp[i][j];
				if (i + n < N)
					dp[i + n][j] += dp[i][j];
			}
		}
	}
	
	cout << dp[N - 1][N - 1] << endl;
	return 0;
}