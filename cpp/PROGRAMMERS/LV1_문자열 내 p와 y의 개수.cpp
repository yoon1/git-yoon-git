#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    for (int i = 0; i < s.size(); i++)
    {
        s[i] = tolower(s[i]); //소문자를 대문자로 교환;
    }

    if (std::count(s.begin(), s.end(), 'y') == std::count(s.begin(), s.end(), 'p'))
        answer = true;
    else
        answer = false;
    return answer;
}