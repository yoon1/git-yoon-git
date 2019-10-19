#include <iostream>

using namespace std;

int main() {
	int N = 0;

	cin >> N;

	
	for (int i = 1; i <= 2 * N - 1; i++) {
		for (int j = 1; j <= 2 * N - 1; j++) {
			if (i <= N && i > j) cout << " ";
			else if (i <= N && 2 * N - i < j) continue;
			else if (i > N && 2 * N - i > j) cout << " ";
			else if (i > N && i < j) continue;
			else cout << "*";
		}
		cout << "\n";
	}
	return 0;
}

/* N = 3
   
   1,1 1,2 1,3 1,4 1,5	1 1 1 1 1  2 3 4 5 6    2*N -1     
   2,1 2,2 2,3 2,4 2,5	0 1 1 1 0  5 6 7 8 9    2*N-1 -1
   3,1 3,2 3,3 3,4 3,5  0 0 1 0 0  7 8 9 10 11  2*N-2 -1
   4,1 4,2 4,3 4,4 4,5  0 1 1 1 0                          
   5,1 5,2 5,3 5,4 5,5  1 1 1 1 1 

*/