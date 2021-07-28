#include <iostream>

using namespace std;

int main() {
	int preGlass, curGlass, needs;
	cin >> preGlass >> curGlass >> needs;
	int glass = preGlass + curGlass;
	int cola = 0;
	while (glass >= needs) {
		int cur = glass / needs;
		cola += cur;
		glass = (glass % needs) + cur;
	}
	
	cout << cola;
	return 0;
}
