#include "pch.h"

#include <iostream>
#include <stack> // stack library. 시험에서는 시간도 없으니깐 stack library를 그냥 사용하는게 일반적입니다.

using namespace std;

int main(void) {
	stack<int> s; // 형태 선언.
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

