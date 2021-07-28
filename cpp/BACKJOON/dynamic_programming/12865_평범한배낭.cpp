#include <iostream>
#include <algorithm>
#include <algorithm>
#include <vector>

using namespace std;

int dp[101][100001]; // 100*10만
int main() {
	int N, K;
	cin >> N >> K;
	vector<pair<int, int>> stuffs(N+1); // W, V(무게, 가치)
	for (int i = 1; i <= N; i++)
		cin >> stuffs[i].first >> stuffs[i].second;
	int idx = 0;
	sort(stuffs.begin(), stuffs.end());
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			if (stuffs[i].first > j)
				dp[i][j] = dp[i - 1][j];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - stuffs[i].first] + stuffs[i].second);
		}
	}

	cout << dp[K] << endl;
	return 0;
}