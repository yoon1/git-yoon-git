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
		dp[0] = 1; // 0�� ���� �� �ִ� �������� 1����� �����մϴ�.
		vector<int> nums = { 1,2,3 }; // ���ĵǾ� �־�� �Ѵ�
		for (int num : nums) 
			for (int i = num; i <= N; i++)
				dp[i] += dp[i - num];
		cout << dp[N] << "\n";

	}

	return 0;
}