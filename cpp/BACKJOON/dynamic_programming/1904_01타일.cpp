#include <iostream>
#define MAX 1000001
using namespace std;

long long dp[MAX];

int main() {
	int N;
	cin >> N;

	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= N; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % 15746;
	}
	cout << dp[N];
	return 0;

}