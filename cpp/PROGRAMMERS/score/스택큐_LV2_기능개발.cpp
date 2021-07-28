
/* 알고리즘은 다 짰는데 지금 대가리가 안돌아감.. ㅠㅠ 시발 알콜성 치매 */

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	vector<int> temp;	
	stack<int> stk;

	int count = 1;
	int ttemp = 0;
	for (int i = 0; i < progresses.size(); i++) {
		stk.push(ceil((100 - progresses[i]*1.0) / speeds[i]));
	}
	cout << "temp생성" << endl;
	
	ttemp = stk.top();
	for (int i = 0; i < stk.size(); i++) {
		if (stk.top() <= ttemp) {
			count++;
		}
		else if (stk.top() > ttemp) {
			answer.push_back(count);
			count = 1;
			ttemp = stk.top();
			
		}
		stk.pop();
	}
	
	answer.push_back(count);
	for (int a : answer) {
	cout << a << endl;
	}

	return answer;
}
int main()
{
	solution({ 93, 30, 55 }, { 1,30,5 });
	//solution({ 5, 5, 5 }, { 21,25,20 });
	return 0;
}