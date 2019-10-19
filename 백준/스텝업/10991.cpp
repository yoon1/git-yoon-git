#include <iostream>

using namespace std;

int main() {
	int N = 0;
	int flag = 0;
	cin >> N;
	for (int i = 0; i < N ; i++) {
		flag = 0;
		for (int j = 0; j<N+i; j++) {
			if (j < N-i-1) cout << " ";
			else {
				if ((++flag) % 2 == 1 && flag >= (2*i-3)) { cout << "*"; }
				else cout << " ";
			}
		}
		cout << endl;
	}
	return 0;
}
/*
0 1
1 0 1

1 0 0 0 1        4-1 = 3        4    N+i
2 0 0 1 0 1      4-2 = 2  3¹ø   5    N+i
3 0 1 0 1 0 1    4-3 = 1  5¹ø   6 
4 1 0 1 0 1 0 1  4-4 = 0  7¹ø   7   

count = 0;

*/