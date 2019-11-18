#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool div10 (string inputNumber ) {
	for (int i = 0; i < inputNumber.length() ; i++) {
		if (inputNumber[i] == '0') {
			return true;
		}
	}
	return false;
}

bool div3(string inputNumber) {
	int addValue = 0;
	for (int i = 0; i < inputNumber.length() ;i++) {
		addValue += (int)inputNumber[i] - '0';
	}
	if (addValue % 3 == 0) {
		return true;
	}
	else return false;
}

bool compare(char a, char b) {
	return a > b;
}
void maxValue(string inputNumber) {
	vector<char> v;
	for (int i = 0; i < inputNumber.length(); i++) {
		v.push_back(inputNumber[i]);
	}

	sort(v.begin(), v.end(), compare);

	for (char a : v) {
		cout << a;
	}
}
int main() {
	
	string inputNumber;
	cin >> inputNumber;
	
	if (div10(inputNumber) && div3(inputNumber)) {
		maxValue(inputNumber);
	}
	else cout << "-1";
	return 0;
}


