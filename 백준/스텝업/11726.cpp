#include <iostream>

using namespace std;

int main () {

	int n = 0;
	int arr[1001] = { 0 };
	double temp = 0;

	cin >> n;

	arr[0] = 1;
	arr[1] = 1;

	for (int i = 2; i <= n; i++) {
		temp = (arr[i - 1] + arr[i - 2]) % 10007;
		arr[i] = temp;
	}

	cout << arr[n];
	return 0;
}