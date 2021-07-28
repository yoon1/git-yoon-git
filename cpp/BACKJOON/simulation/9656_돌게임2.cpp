#include <iostream>

using namespace std;

int N;
int main() {
	cin >> N;

	int result = (N % 2);
	cout << ((result == 0) ? "SK" : "CY") << endl;
	return 0;
}