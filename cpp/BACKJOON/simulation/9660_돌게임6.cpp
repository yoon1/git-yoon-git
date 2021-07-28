#include<iostream>
#include <string>

using namespace std;

long long N;
const string sang = "SK";
const string chang = "CY";
const int MMAX = 1001;
string dp[MMAX][2];
// [i][0] >> i개가 남았을때 상근이 차례
// [i][1] >> i개가 남았을때 창영이 차례
int main()
{
	cin >> N;

	dp[1][0] = chang;
	dp[1][1] = sang;
	dp[2][0] = sang;
	dp[2][1] = chang;

	dp[3][0] = chang;
	dp[3][1] = sang;
	dp[4][0] = sang;
	dp[4][1] = chang;

	for (long long i = 5; i <= N; i++)
	{
		//상근이차례
		int t = (i % 5) + 5;
		dp[t][0] = (dp[t - 1][1] == sang || dp[t - 3][1] == sang || dp[t - 4][1] == sang) ? sang : chang;
		//창영이 차례
		dp[t][1] = (dp[t - 1][0] == chang || dp[t - 3][0] == chang || dp[t - 4][0] == chang) ? chang : sang;
	}

	int t = (N % 5) + 5;
	cout << dp[t][0];

	return 0;

}