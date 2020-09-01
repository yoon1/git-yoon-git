#include <iostream>

using namespace std;

int gcd(int A, int B) {
	int t;
	while (B != 0) {
		t = A % B;
		A = B;
		B = t;
	}
	return A;
}
int main() {
	int T;
	cin >> T;
	for (int testCase = 0; testCase < T; testCase++) {
		int A, B;
		cin >> A >> B;
		cout << A * B / (gcd(A, B)) << "\n";
	}
	return 0;
}
