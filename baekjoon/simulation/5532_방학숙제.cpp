#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

int main() {
	double L, A, B, C, D;
	
	cin >> L >> A >> B >> C >> D;
	cout << L - max(ceil(A / C), ceil(B / D)) << endl;
	return 0;

}