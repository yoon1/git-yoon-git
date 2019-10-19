#include <iostream>

using namespace std;

int main() {
	int naturalNumber;
	std::ios_base::sync_with_stdio(false);
	cin >> naturalNumber;
	if (naturalNumber <= 100000) {
		for (int i = naturalNumber; i >= 1; i--) {
			cout << i << "\n";
		}
	}
	
	return 0;
}