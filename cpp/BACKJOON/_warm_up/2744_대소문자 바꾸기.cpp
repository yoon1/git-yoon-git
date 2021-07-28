#include <iostream>
#include <string>

using namespace std;

int main() 
{
	string str;
	getline(cin, str);
	int t = 'a' - 'A';
	for (int i = 0; i < str.length(); i++) 
	{
		if (str[i] >= 'A' && str[i] <= 'Z') str[i] += t;
		else str[i] -= t;
	}
	cout << str;
	return 0;
}