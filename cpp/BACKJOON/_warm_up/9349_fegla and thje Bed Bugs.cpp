#include <iostream>

using namespace std;

int main(){

	int T;
	cin >> T;
	for (int testCase = 0; testCase < T; testCase++) {
		int N, K;
		cin >> N >> K;
		cout << (N - K) / (K - 1) << endl;
	}
	return 0;
}