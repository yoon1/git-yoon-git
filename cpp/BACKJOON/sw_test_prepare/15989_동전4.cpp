#include <iostream>
#include <vector>

using namespace std;

int main() {
	int T;
	cin >> T;
	for (int testCase = 0; testCase < T; testCase++) {
		int N;
		cin >> N;
		int dp[10001] = { 0 };
		dp[0] = 1; // 0을 만들 수 있는 가짓수가 1개라고 가정합니다.
		vector<int> nums = { 1,2,3 }; // 정렬되어 있어야 한다
		for (int num : nums) 
			for (int i = num; i <= N; i++)
				dp[i] += dp[i - num];
		cout << dp[N] << "\n";

	}

	return 0;
}