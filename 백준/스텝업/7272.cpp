
#include <iostream>
#include <string.h>

using namespace std;

string resultStrNoGlasses(string str) {
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == 'B') {}
		else if (str[i] == 'A' || str[i] == 'D' || str[i] == 'O' || str[i] == 'P' || str[i] == 'Q' || str[i] == 'R') { str[i] = 'O'; }
		else { str[i] = 'I'; }
	}
	return str;
}

int main() {
	string str1 = "";
	string str2 = "";
	int testCase = 0;

	cin >> testCase;
	for (int n = 1; n <= testCase; n++) {
		cin >> str1;
		cin >> str2;

		str1 = resultStrNoGlasses(str1);
		str2 = resultStrNoGlasses(str2);
		if (str1 == str2) {
			cout << "SAME" << endl;
		}
		else { cout << "DIFF" << endl; }
	}
	return 0;
}


