#include <iostream>
#include <memory.h>
#include <algorithm>

using namespace std;

int N;
int arr[1000001];
int dp[1000001];
int main() {
	cin >> N;

	int sol = 1;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		dp[i] = 1;
		for (int j = 0; j < i; j++)
			if (arr[i] > arr[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		sol = max(sol, dp[i]);
	}

	cout << sol << "\n";

	return 0;
}