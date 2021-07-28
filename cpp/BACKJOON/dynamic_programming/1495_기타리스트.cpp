#include <iostream>
#include <algorithm>

using namespace std;

int N, S, M;
int dp[101][1001];
int rslt = -1;
int main() {
	cin >> N >> S >> M;
	dp[0][S] = true;
	for (int i = 1; i <= N; i++) {
		int t;
		cin >> t;
		for (int j = 0; j <= M; j++) {
			if ( dp[i-1][j] ) {
				if (j - t >= 0)
					dp[i][j - t] = true;
				if (j + t <= M)
					dp[i][j + t] = true;
			}
		}
	}
	for (int i = 0; i <= M; i++) {
		if (dp[N][i])
			rslt = i;
	}
	cout << rslt << "\n";

	return 0;
}