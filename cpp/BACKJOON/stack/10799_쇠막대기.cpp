202011#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
	string s;
	int total = 0;
	getline(cin, s);
	stack<char> stk;
	for (int i = 0; i < s.length()-1; i++) {
		if (s[i] == '(') {
			stk.push(s[i]);
			if (s[i + 1] == ')') {
				stk.pop();
				total += stk.size();
				i++;
			}
		}
		else {
			stk.pop();
			total += 1;
		}
	}
	cout << total+1 ;
	return 0;
}
