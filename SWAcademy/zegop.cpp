#include <iostream>
#include <fstream>

using namespace std;


int zegop(int leftNumber, int rightNumber) {
	if (rightNumber == 0) {
		return 1;
	}
	else {
		return leftNumber * zegop(leftNumber, rightNumber - 1);
	}
}
void  main()
{
	ifstream fin;
	ofstream fout;
	int testCase = 0;
	int leftNumber = 0;
	int rightNumber = 0;
	int result = 0;

	fin.open("input\\input_zegop.txt");
		
	for (int i = 0; i < 10; i++) {
		fin >> testCase;
		fin >> leftNumber;
		fin >> rightNumber;
		cout << "#" << testCase << " " << "\n";
		result = zegop(leftNumber, rightNumber);
		cout << result;
		cout << "\n";
	
	}

}

