#include <iostream>
#include <memory.h>
#include <limits.h>
#include <algorithm>
#include <string>

using namespace std;

int N, P;
int dp[1 << 16];// 모든 상태
int cost[16][16];
int state;

int solution(int n, int stat) {
	if (n == P) return 0;
	int& ref = dp[stat]; 
	if (ref != -1) return ref;
	ref = INT_MAX;
	for (int i = 0; i < N; ++i) {
		if (stat & (1 << i)) { // 1이면
			for (int j = 0; j < N; ++j) {
				if (i == j) continue;
				if ((stat & ( 1 << j)) == 0)
					ref = min(ref, solution(n + 1, stat | (1 << j)) + cost[i][j]);
			}
		}
	}
	return ref;
}

int main() {
	memset(dp, -1, sizeof(dp));
	cin >> N;
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++) 
			cin >> cost[i][j];
	string str;
	int count = 0;
	cin >> str >> P;
	for (int i = 0; i < N; i++) {
		if (str[i] == 'Y') {
			state = state | (1 << i); // flag on
			count++;
		}
	}
	if (count == 0) {
		if (P == 0) cout << "0";
		else cout << "-1";
	}
	else if (count >= P) {
		cout << "0";
	}
	else 
		cout << solution(count,state) << endl;
	
	return 0;
}