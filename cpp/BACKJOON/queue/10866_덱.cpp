#include <iostream>
#include <deque>
#include <string>

using namespace std;

deque<int> dq;

bool dqEmptyPrint() {
	if (dq.empty()) {
		cout << "-1" << endl;
		return true;
	}
	return false;
}

int main() {
	int N;
	string str;
	int number;
	
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> str;
		if (str == "push_front") {
			cin >> number;
			dq.push_front(number);
		}
		else if (str == "push_back") {
			cin >> number;
			dq.push_back(number);
		}

		else if (str == "front") {
			if (dqEmptyPrint()) {}
			else cout << dq.front() << endl;
		}
		else if (str == "back") {
			if (dqEmptyPrint()) {}
			else cout << dq.back() << endl;
		}
		else if (str == "empty") {
			if(dq.empty()) cout << "1" << endl;
			else cout << "0" << endl;
		}
		else if (str == "size") {
			cout << dq.size() << endl;
		}
		else if (str == "pop_back") {
			if (dqEmptyPrint()) {}
			else {
				cout << dq.back() << endl;
				dq.pop_back();
			}

		}
		else if (str == "pop_front") {
			if (dqEmptyPrint()) {}
			else {
				cout << dq.front() << endl;
				dq.pop_front();
			}
		}	
	}
	
	return 0;
}