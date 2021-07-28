#include <string>
#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

int changeNumber(char op, string num)
{
    int answer;
    stringstream(num) >> answer;
    if (op == '-')
        answer = -answer;
    return answer;
}
int solution(string s)
{
    int answer = 0;
    if (s[0] == '-')
        answer = changeNumber('-', s.substr(1));
    else if (s[0] == '+')
        answer = changeNumber('+', s.substr(1));
    else
        answer = changeNumber('+', s);
    return answer;
}