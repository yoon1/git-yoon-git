#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
	stack<int> stk; // int 스택
	
	stk.pop();

	return 0;
}
/*
int main(void) {
	int n;
	cin >> n;

	stack<int > st; // int type의 stack선언
	string str;

	for (int i = 0; i < n; i++) {
		cin >> str;

		if (str == "push") { // push 명령어일때
			int num;
			cin >> num;
			st.push(num);
		}
		else if (str == "pop") {
			if (!st.empty()) {
				cout << st.top() << endl; // top 에 있는 거 꺼내서 출력하고.
				st.pop(); // pop시키기 -w-
			}
			else {
				cout << "-1" << endl; // 비어있으면. underflow.
			}
		}
		else if (str == "size") { // size 명령이면.
			cout << st.size() << endl;
		}
		else if (str == "empty") { // empty 명령일때.
			if (st.empty()) {
				cout << "1" << endl;
			}
			else {
				cout << "0" << endl;
			}
		}
		else if (str == "top") {
			if (!st.empty()) {
				cout << st.top() << endl;
			}else {
				cout << "-1" << endl;
			}
		}
	}
	return 0;
}
*/