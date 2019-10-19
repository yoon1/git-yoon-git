/*
#include <iostream>
#include <fstream>

using namespace std;
const int MAX = 200;

int main() {
	ifstream fin;
	ofstream fout;
	int num[MAX] = { 0 };
	int N = 0;
	fin.open("input\\input_2063_sw.txt");

	fin >> N;
	for (int i =0 ; i < N; i++) {
		fin >> num[i];	
	}

	for (int i = 0 ; i < N; i++) {
		int temp = 0 ;
		for (int j = 0 ; j < N; j++) {
			if (num[i] < num[j]) {
				temp = num[i]; 
				num[i] = num[j];
				num[j] = temp;
			}
		}
	}
	cout << num[N/2] << " " ;
	return 0;
}

*/

#include <iostream>

using namespace std;
const int MAX = 200;

int main() {
	int num[MAX] = { 0 };
	int N = 0;
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}

	for (int i = 0; i < N; i++) {
		int temp = 0;
		for (int j = 0; j < N; j++) {
			if (num[i] < num[j]) {
				temp = num[i];
				num[i] = num[j];
				num[j] = temp;
			}
		}
	}
	cout << num[N / 2] << " ";
	return 0;
}

