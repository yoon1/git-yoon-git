#include <iostream>

using namespace std;

void inputNumber(char* num){
	for (int i = 2; i >= 0; i--) {
		cin >> num[i];
	}
}

void printNumber(char* num) {
	for (int i = 0; i < 3; i++) {
		cout << num[i];
	}
}

int main() {
	char A[3], B[3];
	inputNumber(A);
	inputNumber(B);
	for (int i = 0; i < 3; i++) {
		if (A[i] > B[i]) {
			printNumber(A);
			break;
		}
		if (B[i] > A[i]) {
			printNumber(B);
			break;
		}
	}
	return 0;
}
