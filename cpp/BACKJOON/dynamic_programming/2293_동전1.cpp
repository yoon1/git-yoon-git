#include <iostream>
#include <vector>
#define MAX 10001

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);

	int N, M;

	vector<int> v;
	int dp[MAX] = { 0 };

	cin >> N >> M;
	for (int i = 0; i < N; i++) { 
		int temp;
		cin >> temp;
		v.push_back(temp); 
	}
	
	dp[0] = 1; 
	for(int i=0; i < v.size(); i++) {
		for (int j = v[i] ; j <= M ; j++) {
			dp[j] = dp[j] + dp[j - v[i]];
		}
	}
	cout << dp[M];
	return 0;
}