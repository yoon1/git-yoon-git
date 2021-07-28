#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
#include <iterator>

using namespace std;

vector<string> getTokens(const string& str, const string& delimiters = " <>")
{
	string::size_type lastPos = str.find_first_not_of(delimiters, 0); // 맨 처음 문자가 구분자일 때
	string::size_type pos = str.find_first_of(delimiters, lastPos);     // 구분자 찾기
	vector<string> tokens;
	while (string::npos != pos || string::npos != lastPos)
	{
		tokens.push_back(str.substr(lastPos, pos - lastPos)); // 찾은 token을 vector에 저장
		lastPos = str.find_first_not_of(delimiters, pos);        // 구분자 다음으로 이동
		pos = str.find_first_of(delimiters, lastPos);        // 다음구분자 찾기
	}
	return tokens;
}

int main()
{
	string str;
	getline(cin, str);
	vector<string> tokens = getTokens(str);   // default구분자 사용. 여기서는 " "
	for (auto token : tokens)
		cout << token << "\n";
	return 0;

}
