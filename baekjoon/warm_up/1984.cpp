#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;
const int BASE = 10;

int main() {

	ifstream fin;
	ofstream fout;
	fin.open("input\\input_1984_sw.txt");

	int N = 0;
	int num[10] = { 0 };

	fin >> N;

	for (int i = 0; i < N; i++) {
		int result = 0;

		for (int j = 0; j < BASE; j++) {
			fin >> num[j];
		}
		cout << "sort :: " << endl;
		for (int n = 0; n < BASE; n++) {
			int temp = 0;
			for (int m = 0; m < BASE; m++) {
				if (num[n] < num[m]) {
					temp = num[n];
					num[n] = num[m];
					num[m] = temp;
				}
				if (n == 9) cout << num[m] << " ";
			}
		}
		cout << endl;
		cout << "after :: " << endl;
		for (int n = 1; n < BASE - 1; n++) {
			result = result + num[n];
			cout << num[n] << " ";
		}
		cout << endl;

		cout << "#" << i + 1 << " " << round(result / ((BASE-2) * 1.0)) << "\n";
	}

	return 0;
}


#include <iostream>
#include <math.h>

using namespace std;
const int BASE = 10;
int main() {

	int N = 0;
	int num[10] = { 0 };

	cin >> N;

	for (int i = 0; i < N; i++) {
		int result = 0;

		for (int j = 0; j < BASE ; j++) {
			cin >> num[j];
		}

		for (int n = 0; n < BASE; n++) {
			int temp = 0;
			for (int m = 0; m < BASE; m++) {
				if (num[n] < num[m]) {
					temp = num[n];
					num[n] = num[m];
					num[m] = temp;
				}
			}
		}

		for (int n = 1; n < BASE - 1; n++) {
			result = result + num[n];
		}
		cout << "#" << i+1 << " " << round(result / ((BASE-2)*1.0)) << "\n";
	}

	return 0;
}
