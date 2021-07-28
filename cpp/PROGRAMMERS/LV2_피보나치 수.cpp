#include <string>
#include <vector>

using namespace std;

int dp[100001];

int fibo(int n)
{
    if (n < 2)
        return n;
    if (dp[n] != 0)
        return dp[n] % 1234567;
    else
    {
        dp[n] = fibo(n - 1) + fibo(n - 2);
        return dp[n] % 1234567;
    }
}
int solution(int n)
{
    return fibo(n);
}