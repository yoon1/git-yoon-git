#include <string>
#include <cctype>
#include <vector>

using namespace std;

string solution(string s)
{
    int cnt = 1;
    for (int i = 0; i < s.length(); ++cnt, i++)
    {
        if (s[i] == ' ')
            cnt = 0;
        if (cnt == 1)
            s[i] = toupper(s[i]);
        else
            s[i] = tolower(s[i]);
    }
    return s;
}