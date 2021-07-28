#include <iostream>

using namespace std;

int main() {
	long long total = 0, N;
	cin >> N;
	for (long long i = 1; i < N; i++) {
		total += (i * N + i);
	}
	cout << total;
	return 0;
}

