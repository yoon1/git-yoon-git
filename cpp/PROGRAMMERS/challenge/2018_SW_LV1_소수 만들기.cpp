#include <iostream>
#include <vector>

using namespace std;

int answer;
bool isDecimal(int n)
{
    for (int i = 2; i < n; i++)
        if (n % i == 0)
            return false;
    return true;
}

void dfs(int idx, vector<int> nums, vector<int> t, int sum)
{
    if (t.size() >= 3)
    {
        if (isDecimal(sum))
            answer++;
        return;
    }
    for (int i = idx + 1; i < nums.size(); i++)
    {
        t.push_back(nums[i]);
        dfs(i, nums, t, sum + nums[i]);
        t.pop_back();
    }
}
int solution(vector<int> nums)
{
    int size = nums.size();
    vector<int> t;
    dfs(-1, nums, t, 0);
    return answer;
}