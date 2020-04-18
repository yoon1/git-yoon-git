#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int dp[1000001][2];

int solution(vector<int> money) {
	int answer = 0;
	int size = money.size();
	dp[0][0] = money[0];
	dp[1][0] = money[0];
	dp[0][1] = 0;
	dp[1][1] = money[1];

	for (int i = 2; i < size; i++) {
		dp[i][0] = max(dp[i - 2][0] + money[i], dp[i - 1][0]);
		dp[i][1] = max(dp[i - 2][1] + money[i], dp[i - 1][1]);
	}

	answer = max(dp[size - 2][0], dp[size - 1][1]);

	return answer;
}

int main() {
	cout << solution({ 1,2,3,1 }) << endl;
	return 0;
 }