#include <iostream>
#include <limits.h>
#include <algorithm>
#include <string>

using namespace std;

int N, P;
string str;
int state;
int dp[1 << 17];
int arr[17][17];

int dfs(int n, int state) {
	if (n == P) return 0;
	int& ref = dp[state];
	if (ref != -1) return ref;
	ref = INT_MAX;
	for(int i = 0; i < N; i++) {
		if (state & (1 << i)) {
			for (int j = 0; j < N; j++) {
				if (i == j) continue;
				if ((state & (1 << j) == 0))
					ref = min(ref, dfs(n + 1, state | (1 << j)) + arr[i][j]);
			}
		}
	}
	return ref;
}

int main() {
	memset(dp, -1, sizeof(dp));
	cin >> N;
	int count = 0;
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++) 
			cin >> arr[i][j];

	cin >> str >> P;

	for (int i = 0; i < str.length(); i++)
		if (str[i] == 'Y') { 
			state = (state | 1 << i);
			count++;
		}

	if (count == 0) {
		if (P == 0) cout << "0";
		else cout << "-1";
	}
	else if (count >= P) {
		cout << "0";
	}
	else
		cout << dfs(count, state) << endl;

	return 0;
}