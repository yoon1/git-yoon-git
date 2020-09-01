#include <iostream>
#include <memory.h>

using namespace std;

long long dp[1000000];
int main() {
	int T;
	cin >> T;
	for (int testCase = 0; testCase < T; testCase++)
	{
		int N;
		cin >> N;
		for (int i = 1; i <= N; i++) 
			dp[i] = 0;
		dp[1] = 1;
		dp[2] = 2;
		dp[3] = 4;
		for (int i = 4; i <= N; i++)
			dp[i] = ( dp[i - 1] + dp[i - 2] + dp[i - 3] ) % 1000000009;
		cout << dp[N] << endl;
	}
	
	return 0;
}
