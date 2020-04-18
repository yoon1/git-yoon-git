#include <iostream>

using namespace std;

int main() {
	int testCase = 0;
	int N = 0;
	cin >> testCase;
	for (int i = 1; i <= testCase; i++) {
		cin >> N;
		if (N % 2 == 1) {
			cout << "#" << i << " " << (N / 2) * (-1) + N << endl;
		}
		else if (N % 2 == 0) {
			cout << "#" << i << " " <<  (N / 2) * (-1) << endl;
		}
		
	}
	return 0;
}
/* 
N이 홀수인 경우, 2개의 -1과 마지막 숫자 = 5
N이 짝수인 경우, 3개의 -1

*/