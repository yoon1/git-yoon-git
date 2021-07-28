#include <iostream>

using namespace std;

int N;
int dp[1001];
int main() {
	cin >> N;
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 0;
	dp[4] = 0;

	for (int i = 5; i <= N; i++) {
		bool flag = i % 2;
		// �ڱ� ���ʿ� �̱� �� �ִ� �� �ϳ��� ������?
		if (flag == dp[i - 1] || flag == dp[i - 3] || flag == dp[i - 4]) 
			dp[i] = flag;
		else
			dp[i] = !flag;
	}
	cout << ( ( dp[N] == 0 ) ? "CY" : "SK" ) << endl;
	return 0;
}