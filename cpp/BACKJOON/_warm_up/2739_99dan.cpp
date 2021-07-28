#include <iostream>

using namespace std;

int main() {
	int level = 0;
	cin >> level;
	for (int i = 1; i <= 9; i++) {
		cout << level << " * " << i << " = " << level * i << "\n";
	}
	return 0;
}