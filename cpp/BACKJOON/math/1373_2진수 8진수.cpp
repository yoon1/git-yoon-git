#include <iostream>
#include <string>

using namespace std;

int main() {
	string str;
	cin >> str;
	
	int t = str.length() % 3;
	string front_str = (t == 1) ? "00" : (t == 2) ? "0" : "" ;
	
	str = front_str + str;
	
	string new_str = "";
	for (int i = 0; i < str.length(); i = i + 3) {
		int val = 0;
		int n1 = (int)( str[i] - '0' );
		int n2 = (int)( str[i+1] - '0');
		int n3 = (int)( str[i+2] - '0');
		val += n1 * 4;
		val += n2 * 2;
		val += n3 * 1;
		new_str += char(val + '0');
	}
	cout << new_str;
	return 0;
} 