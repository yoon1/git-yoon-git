#include <iostream>
#include <string>

using namespace std;

int main() {
	int T;
	cin >> T;
	for (int testCase = 0; testCase < T; testCase++) {
		int N;
		cin >> N;
		pair<string, int> best = { "",0 };
		for (int i = 0; i < N; i++) {
			pair<string, int> t;
			cin >> t.first >> t.second;
			best = (best.second < t.second) ? t : best;
		}
		cout << best.first << "\n";
	}
	
	return 0;
}