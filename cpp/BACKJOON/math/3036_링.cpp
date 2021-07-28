#include <iostream>
#include <algorithm>

using namespace std;

void printFraction(int x, int y) {
	int minValue = min(x, y); 
	for (int i = 2; i <= minValue; i++) {
		if (x % i == 0 && y % i == 0) {
			x /= i;
			y /= i;
			i--;
		}
	}
	cout << x << "/" << y << "\n";
}

int main() {
	int N;
	cin >> N;
	int denominator; // �и�

	cin >> denominator;
	for (int i = 0; i < N-1; i++) {
		int numerator;//����
		cin >> numerator;
		printFraction(denominator, numerator);
	}

	return 0;
}