#include <iostream>

using namespace std;

int N, K;

int factorial(int n) {
	if (n == 1) return 1;
	return n * factorial(n - 1);
}


int main() {
	cin >> N >> K;
	if (K == 0 || N == K) { cout << 1; }
	else { cout << factorial(N) / factorial(N - K) / factorial(K); }
	return 0;
}