#include <iostream>

using namespace std; 
	
long long gcd(long long a, long long b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}

int main() {
	long long N, M;
	cin >> N >> M;
	long long m = gcd(N, M);
	cout << N * M / m << endl;
	return 0;
}