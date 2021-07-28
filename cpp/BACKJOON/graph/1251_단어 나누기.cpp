#include <iostream>
#include <set>
#include <string>
#include <cstring>

using namespace std;

set<string> s;

int main() {
	string str;
	cin >> str;
	int len = str.length();
	for (int front = 1; front < len-2; front++) {
		for (int back = 2; back < len-1; back++) {
			string s1 = str.substr(0,front); // ¿ø¼Ò °¹¼ö
			string s2 = str.substr(front,back-front);
			string s3 = str.substr(back);
			cout << "#" << s1 << "," << s2 << "," << endl;
			s.insert(s1 + s2 + s3);
		}
	}
	cout << *s.begin();
	return 0;
}