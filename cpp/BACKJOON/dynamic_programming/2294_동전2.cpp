#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n, k;
	
	int coin[101] = { 0 };
	int dp[10001] = { 0 };

	cin >> n >> k;

	for (int i = 1; i <= n; i++) cin >> coin[i];
	
	for (int i = 1; i <= k; i++) dp[i] = 10001;
	
	for (int i = 1; i <= n; i++) 
		for (int j = coin[i]; j <= k; j++) 
			dp[j] = min(dp[j], dp[j - coin[i]] + 1);
	
	if (dp[k] == 10001)
		cout << -1 << endl;

	else 
		cout << dp[k] << endl;

	return 0;
}
