#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	// Ctrl-A : 화면 전체 선택
	// Ctrl-C : 선택 내용 버퍼에 복사 (A->C)
	// 버퍼 없으면 붙여넣기
	// 1. screen + 1, buffer
	// 2. all select (3의 선행)
	// 3. screen, screen (4의 선행)
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