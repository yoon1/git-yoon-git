#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

map<int, int> m;
int main() {
	int tot = 0;
	for (int i = 0; i < 10; i++) {
		int num;  cin >> num;
		tot += num;
		m[num]++;
	}

	pair<int, int> f = { 0,0 };
	for (auto it = m.begin(); it != m.end(); it++) {
		if (it->second > f.second) {
			f.first = it->first;
			f.second = it->second;
		}
	}

	cout << tot / 10 << "\n" << f.first << "\n";
	
	return 0;
}