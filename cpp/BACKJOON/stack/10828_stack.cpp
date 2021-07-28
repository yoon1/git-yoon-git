#include <iostream>
#include <stdio.h>
#include <string>
#define MAX 1000

using namespace std;

int stk[MAX];
int vtop = -1;

void push(int x) {
	if (++vtop > MAX) {
		printf("overflow\n");
		vtop--;
		return;
	}
	stk[vtop] = x;
}
void pop() {
	if (0 > vtop ) {
		printf("%d\n", vtop);
		return;
	}
	printf("%d\n", stk[vtop--]);
}

void size() {	
	printf("%d\n", vtop + 1);
}

void empty() {
	if (vtop == -1)	printf("1\n");
	else printf("0\n");
}

void top() {
	if (vtop == -1) printf("-1\n");
	else printf("%d\n",stk[vtop]);
}

int main() {
	string str;
	int x;
	int N;

	std::ios_base::sync_with_stdio(false);

	cin >> N;
	
	for (int i = 0; i < N; i++) {
		cin >> str;
		if (str == "push") {
			cin >> x;
			push(x);
		}
		else if (str == "top") top();
		else if (str == "size") size();
		else if (str == "pop")pop(); 
		else if (str == "empty") empty();
	}
}
