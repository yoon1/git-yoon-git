#include <string>
#include <vector>

using namespace std;

int sum(int x)
{
    int answer = 0;
    while (x != 0)
    {
        answer += x % 10;
        x /= 10;
    }
    return answer;
}
bool solution(int x)
{
    int n = sum(x);
    if (x % n == 0)
        return true;
    return false;
}