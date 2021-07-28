#include <iostream>
#include <vector>
using namespace std;

int dp[10001];
int main() {
	int t;
	cin >> t;
	for (int testCase = 0; testCase < t; testCase++) {
		int N; cin >> N;
		vector<int> coins;
		for (int i = 0; i < N; i++) { 
			int coin; cin >> coin; 
			coins.push_back(coin); // coin °ª Ãß°¡
		}
		int target; 
		cin >> target;
		for(int i = 0; i < coins.size(); i++){
			int coin = coins[i];
			for (int i = coin; i <= target; i++) {
				dp[i] = dp[i - coin] + 1;
			}
		}
		cout << dp[N] << "\n";
	}


	return 0;
}