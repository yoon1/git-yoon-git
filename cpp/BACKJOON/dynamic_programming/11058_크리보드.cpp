#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	// Ctrl-A : ȭ�� ��ü ����
	// Ctrl-C : ���� ���� ���ۿ� ���� (A->C)
	// ���� ������ �ٿ��ֱ�
	// 1. screen + 1, buffer
	// 2. all select (3�� ����)
	// 3. screen, screen (4�� ����)
	// 4. screen + buffer, buffer 
	int N;
	cin >> N;
	long long dp[101];
	for (int i = 1; i <= 6; i++)
		dp[i] = i;
	for (int i = 7; i <= N; i++) 
		dp[i] = max(dp[i - 3] * 2, max(dp[i - 4] * 3, dp[i - 5] * 4));
	
	cout << dp[N] << endl;
	return 0;
}