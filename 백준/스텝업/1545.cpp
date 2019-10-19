#include <iostream>

using namespace std;

int main() {
	int N = 0;
	cin >> N;

	for (int i = N; i >= 0; i--) {
		if (i == 0) cout << i;
		else cout << i << " ";
		
	}
	return 0;
}
