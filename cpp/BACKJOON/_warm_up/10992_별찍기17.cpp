#include <iostream>

using namespace std;

int main() {
	int N = 0;
	int flag = 0;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		flag = 0;
		for (int j = 1; j < N + i; j++) {
			if (j <= N - i) cout << " ";
			else {
				if (j== N-i+1) { cout << "*"; }
				else if(j == N + i -1 ) { cout << "*"; }
				else if(i == N ) { cout << "*"; }
				else cout << " ";
				flag++;
			}
		}
		cout << endl;
	}
	return 0;
}
