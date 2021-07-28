// strings and NTCS:
#include <iostream>
#include <string>
using namespace std;

int main()
{
	char myword[] = { 'H', 'e', 'l', 'l', 'o', '\0' };
	cout << myword << endl;
	char myword2[] = "Hello";
	cout << myword2 << endl;
	myword[0] = 'C';
	cout << myword << endl;

	
	return 0;
}