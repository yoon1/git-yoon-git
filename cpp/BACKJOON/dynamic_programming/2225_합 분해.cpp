#include <iostream>
#include <algorithm>
#define SIZE 201

using namespace std;

long long dp[SIZE][SIZE];

const int m = 1000000000;

int main() {
	int N, K;
	cin >> N >> K;
	for (int i = 1; i <= K; i++)
		dp[0][i] = 1;	
	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= K; j++)
			dp[i][j] = (dp[i][j-1] + dp[i - 1][j]) % m;

	cout << dp[N][K];
}