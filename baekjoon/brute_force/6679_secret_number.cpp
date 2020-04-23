#include <iostream>
using namespace std;


int jinsu(int num, int js) {
	int rslt = 0;
	while( num != 0) {
		rslt  += num % js;
		num /= js;
	}
	return rslt;
}
int main() {
	for (int i = 1000; i <= 9999; i++) {
		int v10 = jinsu(i,10);
		if (!v10) continue;
		int v12 = jinsu(i,12);
		if (!v12) continue;
		int v16 = jinsu(i,16);
		if (!v16) continue;
		if (v10 == v12 && v10 == v16)
			cout << i << endl;
	}
	return 0;
 }