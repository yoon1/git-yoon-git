#include <iostream>

using namespace std;

int main() {
	int * a;
	int b;
	cin >> b;
	a = new int[b];
	for (int i = 0; i < b; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < b; i++) {
		cout << a[i];
	}
	return 0;
}