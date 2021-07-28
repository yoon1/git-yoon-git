#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, N, M;
	cin >> T;
	for (int testCase = 1; testCase <= T; testCase++) {
		cin >> N >> M;
		vector<pair<int, int>> v(M);
		int answer = 0;
		vector <int> ans_closet;
		for (int i = 0; i < M; i++)
			cin >> v[i].first >> v[i].second;
		for (int i = 1; i < (1 << M); i++) {
			pair<int, int> sum = { 0,0 };
			vector<int> t_closet;
			for (int k = 0; k < M; k++)
				if (i & (1 << k) && sum.first + v[k].first <= N) {
					sum.first += v[k].first;
					sum.second += v[k].second;
					t_closet.push_back(k);
				}
			if (sum.second > answer) {
				ans_closet = t_closet;
				answer = sum.second;
			}
		}
		cout << "#" << testCase << " ";
		for (int i = 0; i < ans_closet.size(); i++) {
			cout << ans_closet[i] << " ";
		}
		cout << answer << "\n";
	}
	return 0;
}