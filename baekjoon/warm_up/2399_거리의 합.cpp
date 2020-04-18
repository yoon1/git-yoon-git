#include <iostream>

using namespace std;

int main() {
	long long N;
	long long M[10000];
	long long total = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> M[i];
	}
	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			total += 2 * abs(M[i] - M[j]);
		}
	}
	cout << total;
	return 0;
}
