#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	vector<int> v = { 1,2,3,4 };
	do {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << " ";
		}
		cout << "\n";
	} while (next_permutation(v.begin(), v.end()));

	return 0;
}
