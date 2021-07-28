#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees)
{
    int answer = 0;
    int skill_order[26] = {0};
    vector<bool> f;
    for (int idx = 1, i = 0; i < skill.length(); i++)
        skill_order[skill[i] - 'A'] = idx++;
    for (int i = 0; i < skill_trees.size(); i++)
    {
        answer++;
        for (int idx = 1, j = 0; j < skill_trees[i].size(); j++)
        {
            int t = skill_order[skill_trees[i][j] - 'A'];
            if (t > idx)
            {
                answer--;
                break;
            }
            else if (t == idx)
                idx++;
        }
    }
    return answer;
}