#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion)
{
    std::sort(participant.begin(), participant.end());
    std::sort(completion.begin(), completion.end());
    string answer = "";

    for (int i = 0; i < completion.size(); i++)
    {
        if (participant[i] != completion[i])
        {
            answer = participant[i];
            return answer;
        }
    }
    answer = participant.back();
    return answer;
}