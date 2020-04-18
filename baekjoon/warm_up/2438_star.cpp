#include <iostream>

using namespace std;

void starWrite(int i)
{
	for (int j = 1; j <= i; j++) {
		cout << "*";
	}
	
}
void spaceWrite(int i)
{
	for (int j = 1; j <= i; j++) {
		cout << " ";
	}
}

int main() {
	int floor = 0 ;
	int i = 0;
	int j = 0;

	cin >> floor;
	
	for(i = 1; i <= floor ; i++) {		
		starWrite(i);
		spaceWrite(2 * (floor - i));
		starWrite(i);
		cout << "\n";
	}
	for (i = 1; i <= floor - 1; i++) {
		starWrite(floor - i );
		spaceWrite(2 * i);
		starWrite(floor - i);
		cout << "\n";
	}

	return 0;
}

/* 
1 8 1
2 6 2
3 4 3 
4 2 4 
5 0 5 
*/