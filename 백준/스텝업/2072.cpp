#include <iostream>
#include <fstream>

using namespace std;

int main() {
	ifstream fin;
	ofstream fout;
	int testCase = 0; 
	int tempNum = 0;
	int result = 0;
	fin.open("input\\input_2071_sw.txt");

	fin >> testCase;

	for (int i = 1; i <= testCase; i++) {
		result = 0;
		for (int j = 0; j < 10; j++) {
			fin >> tempNum;
			result = result + tempNum;
		}
		cout << "#" << i << " " << round(result/10.0) << "\n";
	}
	
}

/*
#include <iostream>

using namespace std;

int main() {
	int testCase = 0;
	int tempNum = 0;
	int result = 0;
	cin >> testCase;

	for (int i = 1; i <= testCase; i++) {
		result = 0;
		for (int j = 0; j < 10; j++) {
			cin >> tempNum;
			result = result + tempNum;
		}
		cout << "#" << i << " " << round(result/10.0) << "\n";
	}

}
*/