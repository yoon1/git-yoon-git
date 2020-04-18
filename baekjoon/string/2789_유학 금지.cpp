#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main() {
	set<char> s =  { 'C','A','M','B','R','I','D','G','E' };
	char c;
	while (cin.get(c)) {
		if (c == '\n') break;
		if (s.find(c) == s.end()) cout << c;
	}
}
