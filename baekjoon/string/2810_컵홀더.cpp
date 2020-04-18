#include <iostream>

using namespace std;

int main() {
	int N;
	char preC = '0';
	char curC = '0';
	int cnt = 1;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> curC;
		if (curC == 'S') cnt++;
		if (curC == 'L' && preC == 'L') {
			cnt++;
			preC = '0';
		} else 
			preC = curC;
	}
	if (N <= cnt) cnt = N;
	cout << cnt;
	return 0;
}