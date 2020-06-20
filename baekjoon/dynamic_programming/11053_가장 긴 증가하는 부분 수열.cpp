#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[1001], dp[1001];
int result = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		int cur = 0;
		for (int j = 1; j < i; j++) {
			if (arr[i] > arr[j])
				cur = max(cur, dp[j]);
		}
		dp[i] = cur + 1;
		result = max(dp[i], result);
	}

	cout << result << endl;
	return 0;
}