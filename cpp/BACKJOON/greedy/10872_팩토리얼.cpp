#include <iostream>

using namespace std;

int factorial(int N) {
	if (N == 0) return 1;
	if (N == 1) return 1;
	return N * factorial(N-1);
}
int main() {
	int N;
	cin >> N;
	cout << factorial(N) << endl;
	return 0;
}