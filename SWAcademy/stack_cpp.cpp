#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
	stack<int> stk; // int ����
	
	stk.pop();

	return 0;
}
/*
int main(void) {
	int n;
	cin >> n;

	stack<int > st; // int type�� stack����
	string str;

	for (int i = 0; i < n; i++) {
		cin >> str;

		if (str == "push") { // push ��ɾ��϶�
			int num;
			cin >> num;
			st.push(num);
		}
		else if (str == "pop") {
			if (!st.empty()) {
				cout << st.top() << endl; // top �� �ִ� �� ������ ����ϰ�.
				st.pop(); // pop��Ű�� -w-
			}
			else {
				cout << "-1" << endl; // ���������. underflow.
			}
		}
		else if (str == "size") { // size ����̸�.
			cout << st.size() << endl;
		}
		else if (str == "empty") { // empty ����϶�.
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