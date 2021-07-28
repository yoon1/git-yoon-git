#include <iostream>

using namespace std;

int N, M;
int main() {
	cin >> N >> M;
	int num = N * M;
	for (int i = 0; i < 5; i++) {
		int t; cin >> t;
		cout << t - num << " ";
	}
	return 0;
}