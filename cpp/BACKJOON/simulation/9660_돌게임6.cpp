#include<iostream>
#include <string>

using namespace std;

long long N;
const string sang = "SK";
const string chang = "CY";
const int MMAX = 1001;
string dp[MMAX][2];
// [i][0] >> i���� �������� ����� ����
// [i][1] >> i���� �������� â���� ����
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
		//���������
		int t = (i % 5) + 5;
		dp[t][0] = (dp[t - 1][1] == sang || dp[t - 3][1] == sang || dp[t - 4][1] == sang) ? sang : chang;
		//â���� ����
		dp[t][1] = (dp[t - 1][0] == chang || dp[t - 3][0] == chang || dp[t - 4][0] == chang) ? chang : sang;
	}

	int t = (N % 5) + 5;
	cout << dp[t][0];

	return 0;

}