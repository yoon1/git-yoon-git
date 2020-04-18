#include <iostream>
using namespace std;

int main() {
	int A, B, C;
	int result;
	int num[10] = { 0 };

	cin >> A >> B >> C;
	result = A * B * C;

	while ( result != 0 ) {
		num[result % 10]++;
		result = result /  10;
	}
	
	for (int i = 0; i < 10; i++) {
		cout << num[i] << "\n";
	}
	return 0;
}

