#include <iostream>
#include <string>
using namespace std;
#define MAX 100

int main() {
	string str;
	int count = 0;
	while (count++ < 100) {
		getline(cin, str);
		cout << str << "\n";
	}
}