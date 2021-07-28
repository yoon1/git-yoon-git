#include <string>
#include <vector>
#include <regex>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    std::regex number("^[0-9]{4}$|^[0-9]{6}$");
    if (std::regex_match(s, number))
        answer = true;
    else
        answer = false;
    return answer;
}