#include <iostream>

using namespace std;

bool isSosu(int num) {
	if (num < 2) return false;
	for (int i = 2; i < num; i++) {
		if ( num % i == 0 )
			return false;
	}
	return true;
}

int main() {
	int N;
	cin >> N;
	int count = 0;
	for (int i = 0; i < N; i++) {
		int t;
		cin >> t;
		if (isSosu(t))
			count++;
	}
	cout << count << endl;
	return 0;
 }