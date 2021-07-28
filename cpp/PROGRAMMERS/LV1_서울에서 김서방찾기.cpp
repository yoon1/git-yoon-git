#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
	string answer = "";
	vector<string>::iterator it;
	it = find(seoul.begin(), seoul.end(), "Kim");
	
	int idx = distance(seoul.begin(), it);
	
	answer = "�輭���� " + to_string(idx) + "�� �ִ�";
	
	cout << answer;
	
	return answer;
}

int main()
{
	solution({"Jane", "Kim"});
	return 0;
}