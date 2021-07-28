#include <iostream>

using namespace std;

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}
int main() {
	int N;
	cin >> N;
	for(int i = 0; i < N; i++) {
		int a, b; cin >> a >> b;
		int m = gcd(a,b);
		cout << a * b / m << " " << m << endl;
	}
	return 0;
}