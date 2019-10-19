#include <iostream>
using namespace std;

int add(int num) {
	if (num > 0) {
		return num + add(num-1);
	} 
	else return 0;
}
int main() {
	int number = 0; 	
	int result = 0;
	cin >> number;
	result = add(number);
	cout << result;

	return 0;
}