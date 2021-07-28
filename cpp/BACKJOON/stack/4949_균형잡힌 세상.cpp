#include <iostream>
#include <string>
#define MAX 100

using namespace std;

typedef struct stack {
	char space[MAX];
	int top = -1;
};

bool isEmpty(stack *stk) {
	if (stk->top == -1) {
		return true;
	}
	return false;
}

void push(stack *stk, char c) {
	stk->top++;
	stk->space[stk->top] = c;
}

char top(stack *stk) {
	return stk->space[stk->top];
}

bool pop(stack *stk) {
	if (isEmpty(stk)) return false;
	else {
		stk[stk->top--];
		return true;
	}
}

bool balance(string str) {
	stack stk;
	for (int i = 0; i < str.length(); i++) {
		if (str.at(i) == '(' || str.at(i) == '[') {
			push(&stk, str.at(i));
		}
		else if (str.at(i) == ')' || (str.at(i) == ']')) {
			if (isEmpty(&stk)) {
				return false;
			}
			char temp = top(&stk);
			if((str.at(i) == ')' && temp == '(' )||
				str.at(i) == ']' && temp == '[')
				pop(&stk);
			else return false;
		}
	}
	if (!isEmpty(&stk)) {
		return false;
	}
	return true;
}

int main() {
	string str;
	
	while (getline(cin,str)){
		if (str == ".") break;
		if(balance(str)) cout << "yes" << endl;
		else cout << "no" << endl;
	}
	return 0;
}

