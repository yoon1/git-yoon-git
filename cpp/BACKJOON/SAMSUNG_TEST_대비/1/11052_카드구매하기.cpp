#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[1001];
int dp[1001];
int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) 
		cin >> arr[i];
	for (int i = 1; i <= N; i++) {
		dp[i] = arr[i];
		for (int j = 1; j <= i; j++)
			dp[i] = min(dp[i - j] + dp[j], dp[i]);
	}
	cout << dp[N] << endl;
	return 0;
}