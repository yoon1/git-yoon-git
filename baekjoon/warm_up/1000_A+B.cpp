#include <iostream>

using namespace std;

int main() {
	int testCase = 0;
	int A = 0;
	int B = 0;
		
	cin >> testCase;

	for(int i=1; i<=testCase; i++){
		cin >> A >> B;
		cout << "Case #" << i << ": " << A << " + " << B << " = " << A + B << "\n";
	}	
	return 0;
}