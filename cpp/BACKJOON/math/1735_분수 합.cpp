#include <iostream>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main() {
	int A1, A2, B1, B2;
	cin >> A1 >> A2 >> B1 >> B2;
	int ta = A2, tb = B2;
	A1 *= tb, A2 *= tb, B1 *= ta, B2 *= ta;
	
	int r1 = A1 + B1;
	int r2 = A2;
	int m = gcd(min(r1, r2), max(r1, r2));
	cout << r1 / m << " " << r2 / m << endl;
	return 0;

	int total = 0;
	for (int i = 0; i < 5; i++) {
		int t; cin >> t; 
		total += t;
	}
	cout << total;
}

