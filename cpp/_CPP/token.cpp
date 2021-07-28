#include <iostream>
#include <cstring>
using namespace std;

int main() {
	char str[] = "I, can ,do .it!";
	char* token;
	token = strtok(str, " ,.");
	while (token != NULL) {
		cout << token << endl;
		token = strtok(NULL, " ,.");
	}
	return 0;
}