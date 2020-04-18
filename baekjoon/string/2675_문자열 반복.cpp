#include <iostream>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T, N;
	char c;
	cin >> T;
	for (int i = 0; i < T; i++) { // testCase
		cin >> N;
		while (cin.get(c)) {
			if (c == ' ') continue;
			if (c == '\n') break;
			for (int i = 0; i < N; i++) cout << c;
		}
		cout << "\n";
	}
}