#include <iostream>
using namespace std;
const int MAX = 1000000;
int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(0);

	int testCase = 0 ;
	int tempNumber = 0 ;
	int minNumber =  MAX;
	int maxNumber = -1 * MAX;
		
	cin >> testCase;

	for (int i = 0; i < testCase; i++) {
		cin >> tempNumber;
		if (tempNumber < minNumber) minNumber = tempNumber;
		if (tempNumber > maxNumber) maxNumber = tempNumber;
	}

	cout << minNumber << " " << maxNumber;
}
