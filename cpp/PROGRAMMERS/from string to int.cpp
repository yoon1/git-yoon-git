#include <iostream>
#include <sstream>

using namespace std;

int main() {
	int year;

	string mystr;

	getline(cin, mystr);

	(stringstream)mystr >> year;

	cout << year;
}
