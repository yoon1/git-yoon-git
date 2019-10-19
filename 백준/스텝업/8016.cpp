#include <iostream>

using namespace std;

int main() {
	int testCase = 0;
	int N = 0;
	int leftResult = 0;
	int rightResult = 0;

	cin >> testCase;
	for (int i = 1; i <= testCase; i++) {
		leftResult = 0;
		rightResult = 0;
		cin >> N;
		if (N == 1) cout << "#" << i << " " << 1 << " " << 1 << endl;
		else if(N == 2) cout << "#" << i << " " << 3 << " " << 7 << endl;
		else {
			for (int j = N ; j > 2; j--) {
				leftResult = leftResult + (2 + 4 * (N - 2));
				rightResult = rightResult + (2 + 4 * (N - 1));
			}
			cout << "#" << i << " " << 3 + leftResult << " " << 7 + rightResult << endl;
		}
	}
	return 0;
}
