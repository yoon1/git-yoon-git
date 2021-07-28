#include <iostream>
#include <vector>

using namespace std;

int main() {
	int L, N;
	cin >> L >> N;
	pair<int, int> max_anti = { 1, 0 };
	pair<int, int> max_real = { 1, 0 };
	vector<int> v(L+1);
	for (int people = 1; people <= N; people++) {
		pair<int, int> anti;
		int real = 0;
		cin >> anti.first >> anti.second;
		if (max_anti.second < (anti.second - anti.first + 1)){
			max_anti.first = people;
			max_anti.second = (anti.second - anti.first + 1);
		}
		int count = 0;
		for (int j = anti.first; j <= anti.second; j++) {
			if ( v[j] == 0) {
				v[j] = people;
				count++;
			}
		}
		if (max_real.second < count) {
			max_real.first = people;
			max_real.second = count;
		}
	}

	cout << max_anti.first << endl;
	cout << max_real.first << endl;

	return 0;
 }