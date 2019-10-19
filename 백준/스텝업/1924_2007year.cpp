#include <iostream>
#include <string>
using namespace std;

int main() {
	
	int month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	string dayOfWeek[7] = { "SUN" , "MON", "TUE", "WED", "THU", "FRI", "SAT" };

	int inputMonth = 0;
	int inputDay = 0;
	int count = 0;
	string result = "";

	cin >> inputMonth >> inputDay;

	for (int i = 1; inputMonth != 1 && i < inputMonth ; i++) {
		count += month[i-1];
	}
	count += inputDay;
	cout << dayOfWeek[count % 7] ;
	return 0;
}

