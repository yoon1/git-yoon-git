#include <iostream>
#include <string>
using namespace std;

int sameNumber(string a, string b) {
	int count = 0;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] == b[i]) {
			count++;
		}
	}
	return count;
}

int main() {
	string A, B;
	int current = 0;
	int max = 0;
	cin >> A >> B;

	for (int i = 0; i <= B.length() - A.length(); i++) {
		current = sameNumber(A, B.substr(i, i + A.length()));
		if (current > max) {
			max = current;
		}
	}
	
	cout << B.length() - (B.length() - A.length() + max );
	
	return 0;
}