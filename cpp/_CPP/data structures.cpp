// pointers to structures
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

struct movies_t {
	string title;
	int year;
};

int main()
{
	string mystr;
	movies_t amovie;
	movies_t * pmovie;
	pmovie = &amovie;

	cout << "Enter title: ";
	getline(cin, pmovie->title);
	cout << "\nYou have entered:\n";
	cout << "1" << pmovie->title << endl;
	cout << "2" << (*pmovie).title << endl;
	cout << "3" << *pmovie.title << endl;
	cout << "4" << *(pmovie.title) << endl;


	return 0;
}