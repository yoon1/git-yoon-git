#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long solution(int N) {
	long long answer = 0;
	long long dp[81][2] = { 0 };
	dp[1][0] = 1;
	dp[1][1] = 1;
	for (int i = 2; i <= N; i++) {
		dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
		dp[i][1] = dp[i - 1][0];
	}
	answer = 2 * (dp[N][0] + dp[N][1]);
	return answer;
}

int main() {
	cout << solution(5);
	cout << solution(6);
	return 0;
}
