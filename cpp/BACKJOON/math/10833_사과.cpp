#include <iostream>

using namespace std;

int N;
int main() {
	cin >> N;
	int ret = 0;
	for (int i = 0; i < N; i++) {
		int a, b; cin >> a >> b;
		ret += b % a;
	}
	cout << ret;
	return 0;
}