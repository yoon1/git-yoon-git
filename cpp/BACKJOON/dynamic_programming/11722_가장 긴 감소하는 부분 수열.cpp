#include <iostream>
#include <algorithm>
#define MAX 1001
//#define INF 2e8

using namespace std;

int main() {
	int N;
	int arr[MAX] = { 0 };
	int dp[MAX] = { 0 };
	int result = 0;
	cin >> N; // 수열의 크기

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		int currne_max_len = 0;
		for (int j = 0; j < i; j++) {
			if (arr[i] < arr[j] && dp[j] > currne_max_len)
				currne_max_len = dp[j];
		}
		dp[i] = 1 + currne_max_len;
		result = max(result, dp[i]);
	}
	cout << result;
	return 0;
}
