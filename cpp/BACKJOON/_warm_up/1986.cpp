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
N�� Ȧ���� ���, 2���� -1�� ������ ���� = 5
N�� ¦���� ���, 3���� -1

*/