#include <string>
#include <vector>

using namespace std;

string solution(string s, int n)
{
    string answer = "";
    for (int i = 0; i < s.length(); i++)
    {
        string t = "";
        if (s[i] >= 'A' && s[i] <= 'Z')
            t = ((s[i] - 'A' + n) % 26) + 'A';
        else if (s[i] >= 'a' && s[i] <= 'z')
            t = ((s[i] - 'a' + n) % 26) + 'a';
        else
            t = s[i];
        answer += t;
    }
    return answer;
}