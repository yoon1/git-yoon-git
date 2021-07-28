#include <iostream>
#include <algorithm>

using namespace std;
int dp[333][2];

int main() {
	int N;
	cin >> N;
	int cur, pre;
	for (int i = 1; i <= N; i++) {
		cin >> cur;
		if (i == 1) {
			dp[i][0] = cur;
			dp[i][1] = 0;
		}
		else if (i == 2) {
			dp[i][0] = dp[i - 1][0] + cur;
			dp[i][1] = dp[i - 1][0];
		}
		else {
			dp[i][0] = max(dp[i-2][1] + pre + cur, dp[i-2][0] + cur);
			dp[i][1] = max(dp[i-1][0], dp[i-2][1]);
		}
		pre = cur;
	}
	
	cout << dp[N][0]; 
	return 0;
}