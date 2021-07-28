#include <iostream>
#include <string>

using namespace std;

int N;

int main() {
	cin >> N;
	
	long long result = (N % 2);
	cout << ((result == 1) ? "SK" : "CY" ) << endl;
	return 0;
}