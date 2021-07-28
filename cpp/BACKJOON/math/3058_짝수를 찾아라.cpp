#include <iostream>
#include <algorithm>
#define INF 2e8

using namespace std;

int main() {
	int T; cin >> T;
	for (int i = 0; i < T; i++) {
		int tot = 0, min_val = INF;
		for (int j = 0; j < 7; j++) {
			int num; cin >> num;
			if (num % 2 == 0) {
				tot += num;
				min_val = min(min_val, num);
			}
		}
		cout << tot << " " << min_val << endl;
	}
	return 0;
}