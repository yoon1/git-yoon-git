#include <iostream>

using namespace std;

 int main() {
	int R, B;
	cin >> R >> B;
	int sero = 1; 
	int garo = B;
	int idx = 1;
	while (sero <= B) {
		if (B % sero == 0) {
			garo = B / sero;
			if (R == (((garo + sero) * 2) + 4)) {
				cout << garo + 2 << " " << sero + 2 << endl;
				return 0;
			}
		}
		sero++;
	}
	return 0;
 }
