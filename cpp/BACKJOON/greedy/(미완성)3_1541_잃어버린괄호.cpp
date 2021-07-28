#include <iostream>
#include <string>
#include <sstream>

using namespace std;


int getString(string number) {
	int answer = 0;
	ss(number);
	ss >> answer;
	return answer;
}
int main() {
	string inputStr;
	int result = 0;
	bool flag = false;
	cin >> inputStr;
	
	for (int i = 0; i < inputStr.size(); i++) {
		string temp = "";
		if (inputStr[i] == '+' || inputStr[i] == '-') {		
			if (flag == false && inputStr[i] == '+') {
				result += getString(temp);
			} else if(flag == false && inputStr[i] == '-') {
				result -= getString(temp);
			}
		} else {
			temp += inputStr[i];
			
		}
	}
	return 0;
}