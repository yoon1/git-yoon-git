// inner block scopes
#include <iostream>
using namespace std;

int foo = 100 ;        // global variable

int some_function()
{
	int bar;      // local variable
	bar = 0;
	return bar;
}

int other_function()
{
	foo = 1;  // ok: foo is a global variable
	return 0;
}

int main() {
	cout << foo << endl;
	foo = 1000;
	cout << foo << endl;
	other_function();
	cout << foo << endl;
	return 0;
}