#include <iostream>
#include <deque>
#include <string>

using namespace std;

deque<char> dq;

void dq_print(char c, bool reverse) {
	while (!dq.empty()) {
		cout << (reverse ? dq.front() : dq.back());
		reverse ? dq.pop_front() : dq.pop_back() ;
	}
	if (c != 'X') cout << c;
}

int main() {
	string s;

	getline(cin, s);
	bool flag = false;
	for (int i = 0; i < s.length(); i++) {
		switch (s[i]) {
		case '<':
			dq_print(s[i], flag);
			flag = true;
			break;
		case '>':
			dq_print(s[i], flag);
			flag = false;
			break;
		case ' ':
			if (flag) {
				dq.push_back(s[i]);
				break;
			}
			dq_print(s[i], flag);
			break;
		default:
			dq.push_back(s[i]);
			break;
		}
	}
	dq_print('X', flag);
	return 0;
}