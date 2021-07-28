#include <iostream>

using namespace std;

int N;
int main() { 
	cin >> N;
	int a, b, c;
	a = N / 300;
	N = N % 300;
	b = N / 60;
	N = N % 60;
	c = N / 10;
	N = N % 10;
	if (N != 0) cout << "-1";
	else cout << a << " " << b << " " << c;

	return 0;
}