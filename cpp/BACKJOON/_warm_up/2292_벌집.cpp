#include <iostream>

using namespace std;

int main() {
	int N;
	cin >> N;
	int layer = 1, cur = 2;

	if (N > 1) 
		while (N >= cur)
			cur += 6 * (layer++);

	cout << layer;
	return 0;
}