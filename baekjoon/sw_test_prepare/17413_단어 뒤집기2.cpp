#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
#include <iterator>

using namespace std;

vector<string> getTokens(const string& str, const string& delimiters = " <>")
{
	string::size_type lastPos = str.find_first_not_of(delimiters, 0); // �� ó�� ���ڰ� �������� ��
	string::size_type pos = str.find_first_of(delimiters, lastPos);     // ������ ã��
	vector<string> tokens;
	while (string::npos != pos || string::npos != lastPos)
	{
		tokens.push_back(str.substr(lastPos, pos - lastPos)); // ã�� token�� vector�� ����
		lastPos = str.find_first_not_of(delimiters, pos);        // ������ �������� �̵�
		pos = str.find_first_of(delimiters, lastPos);        // ���������� ã��
	}
	return tokens;
}

int main()
{
	string str;
	getline(cin, str);
	vector<string> tokens = getTokens(str);   // default������ ���. ���⼭�� " "
	for (auto token : tokens)
		cout << token << "\n";
	return 0;

}
