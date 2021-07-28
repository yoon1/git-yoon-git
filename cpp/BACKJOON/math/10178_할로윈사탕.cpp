#include <iostream>

using namespace std;

int N;
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int c, v; cin >> c >> v;
		cout << "You get " << c/v << " piece(s) and your dad gets "<< c%v <<" piece(s).\n";
	}

	return 0;
}
