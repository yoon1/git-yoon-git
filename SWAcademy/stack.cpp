#include <iostream>
#define MAX 100

using namespace std;
int stack[MAX] = { 0 };
int top = -1;

void push(int x);
int pop();

int main() {
	
//	push(1);
//	push(2);
//	push(3);
	cout << pop() << endl;
	cout << pop() << endl;
	cout << pop() << endl;

	return 0;
}

void push(int x) {
	if (++top > MAX) {
		cout << "OverFlow" << endl;
		return;
	}
	stack[top] = x;
	cout << "push top : " << top << endl;
}

int pop() {
	if (top == -1) {
		cout << "UnderFlow" << endl;
		return 0;
	}
	cout << "pop top : " << top << endl;
	return stack[top--];
}