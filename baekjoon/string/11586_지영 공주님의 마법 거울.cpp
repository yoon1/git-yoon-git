#include <iostream>
#include <string>

using namespace std;

int main() {
	char mirror[100][100] = {};
	int N, S;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> mirror[i][j];
		}
	}
	cin >> S;
	switch (S) {
		case 1 : 
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					cout << mirror[i][j];
				}
				cout << "\n";
			}
			break;
		case 2 :
			for (int i = 0; i < N; i++) {
				for (int j = N-1; j >= 0; j--) {
					cout << mirror[i][j];
				}
				cout << "\n";
			}
			break;
		case 3 :
			for (int i = N-1; i >= 0; i--) {
				for (int j = 0; j < N; j++) {
					cout << mirror[i][j];
				}
				cout << "\n";
			}
			break;
		default: 
			break;
	}
	
	return 0;
}