#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool solution(vector<string> phone_book) {
	bool answer = true;
	int position = 0;
	std::sort(phone_book.begin(), phone_book.end());
	for (int i = 0; i < phone_book.size()-1; i++) {
		std::string str_front = std::string(phone_book[i]);
		std::string str_back = std::string(phone_book[i+1]);
		if (str_front.length() <= str_back.length()) {
			for (int j = 0; j < str_front.length(); j++) {
				cout << "[" << j << "]" << str_front[j] << "," << str_front[j] << endl;
				if (str_front[j] != str_back[j]) break;
				if (j == str_front.length() - 1 && str_front[j] == str_back[j]) {
					answer = false;
					break;
				}
			}
		}
	}
	return answer;
}

int main()
{
	cout << solution({"123", "456", "789"}) << endl; // true 
	cout << solution ({"12", "123", "1235", "567", "88"}) << endl; // false
	cout << solution({"1234", "34", "567"}) << endl; // true
	cout << solution({"0000", "20", "01"}) << endl; // true
	return 0;
}
