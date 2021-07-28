#include <iostream>

using namespace std;

int pins[6] = { 1,1,2,2,2,8 };

int main() {
	for (int i = 0; i < 6; i++)
	{
		int t; cin >> t;
		cout << pins[i] - t << " ";
	}
		
	
	return 0;
}