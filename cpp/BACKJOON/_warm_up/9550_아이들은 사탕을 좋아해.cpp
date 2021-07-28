#include <iostream>

using namespace std;

int T;
int main() {
	cin >> T; 
	for (int testCase = 0; testCase < T; testCase++) 
	{
		int N, K;  cin >> N >> K;
		int child = 0;
		for (int i = 0; i < N; i++) {
			int candy; cin >> candy;
			child += candy / K;
		}
		cout << child << endl;
	}
	return 0;
}