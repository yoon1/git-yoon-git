#include <iostream>
#include <cstdio>
#include <string.h>
#include <vector>

using namespace std;

vector<char> findStr;
vector<char> str;
int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		str.clear();
		findStr.clear();

		int testCaseNumber;
		char c;
		int count = 0;

		scanf_s("%d\n", &testCaseNumber);

		while (cin.get(c)) {
			if (c == '\n') break;
			else findStr.push_back(c);
		}

		while (cin.get(c)) {
			if (c == '\n') break;
			else str.push_back(c);
		}

		for (int i = 0; i <= str.size() - findStr.size(); i++) {
			int corCount = 0;
			for (int j = 0; j < findStr.size(); j++) {
				if (findStr[j] == str[i + j]) {
					corCount++;
				}

			}
			if (corCount == findStr.size())
				count++;
		}

		printf("#%d %d\n", testCaseNumber, count);
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}