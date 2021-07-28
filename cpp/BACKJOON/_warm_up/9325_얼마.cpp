#include <iostream>

using namespace std;

int main() {
	int T;
	cin >> T;
	for (int testCase = 0; testCase < T; testCase++) {
		int s, n;
		cin >> s >> n;
		for (int i = 0; i < n; i++) {
			int q, p;
			cin >> q >> p;
			s += (q * p);
		}
		cout << s << "\n";
	}
	return 0;
}