#include <iostream>

using namespace std;

int N;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a, b; cin >> a >> b;
		cout << 2 * b - a << " " << a - b << "\n";
	}
	return 0;
}
