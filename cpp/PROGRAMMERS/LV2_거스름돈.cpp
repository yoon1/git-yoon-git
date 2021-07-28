#include <string>
#include <algorithm>
#include <vector>

using namespace std;


int solution(int n, vector<int> money) {
    int dp[100001] = {0};
    dp[0] = 1;
    for(int i=0; i < money.size(); i++){
        for(int j = money[i]; j <= n; j++){
            dp[j] = dp[j] + dp[j - money[i]];
        }
    }
    return dp[n];
}