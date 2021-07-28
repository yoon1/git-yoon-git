#include<iostream>
#include <string>

using namespace std;

int N;
const string sang = "SK";
const string chang = "CY";
const int MMAX = 1001;
string dp[MMAX][2];
// [i][0] >> i���� �������� ����� ����
// [i][1] >> i���� �������� â���� ����
int main()
{
	cin >> N;

	dp[1][0] = sang;
	dp[1][1] = chang;
	dp[2][0] = chang;
	dp[2][1] = sang;
	dp[3][0] = sang;
	dp[3][1] = chang;
	dp[4][0] = sang;
	dp[4][1] = chang;

	for (int i = 5; i <= N; i++)
	{
		//���������
		dp[i][0] = (dp[i - 1][1] == sang || dp[i - 3][1] == sang || dp[i - 4][1] == sang) ? sang : chang;
		//â���� ����
		dp[i][1] = (dp[i - 1][0] == chang || dp[i - 3][0] == chang || dp[i - 4][0] == chang) ? chang : sang;
	}

	for (int i = 1; i <= N; i++) {
		cout << i << " : " << dp[i][0] << endl;
	}

	return 0;

}