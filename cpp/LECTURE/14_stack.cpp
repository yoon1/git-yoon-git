#include "pch.h"

#include <iostream>
#include <stack> // stack library. ���迡���� �ð��� �����ϱ� stack library�� �׳� ����ϴ°� �Ϲ����Դϴ�.

using namespace std;

int main(void) {
	stack<int> s; // ���� ����.
	s.push(7);
	s.push(5);
	s.push(3);
	s.pop();
	s.push(6);
	s.pop();

	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}
	return 0;
}

