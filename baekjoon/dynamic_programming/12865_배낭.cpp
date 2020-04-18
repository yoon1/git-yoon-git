#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dp[101][100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, K;
	vector<pair<int, int>> v;
	cin >> N >> K;
	v.push_back(make_pair(0, 0));
	for (int i = 1; i <= N; i++) {
		pair<int, int> t;
		cin >> t.first >> t.second;
		v.push_back(t);
	}
	sort(v.begin(), v.end());

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			if (v[i].first > j)
				dp[i][j] = dp[i - 1][j];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i].first] + v[i].second);
		}
	}
	cout << dp[N][K] << endl;
	return 0;
}

/* https://hydroponicglass.tistory.com/50 */

/* 
4 7
6 13
4 8
3 6
5 12
*/