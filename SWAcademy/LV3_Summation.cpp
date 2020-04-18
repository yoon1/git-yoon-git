#include <iostream>
#include <algorithm>

using namespace std;

int sumIndex(int num) {
	int result = 0;
	while ( num != 0 ) {
		result = result + (num % 10);
		num = num / 10;
	}
	return result;
}

int main() {

	int T;
	cin >> T;
	for(int t=1; t <= T; t++) {
		int maxInt = 0;
		int minInt = 1000001;

		for (int i = 0; i < 10; i++) {
			int num;
			cin >> num;
			int result = sumIndex(num);
			minInt = min(result, minInt);
			maxInt = max(result, maxInt);
		}
		cout << "#" << t << " " << maxInt << " " << minInt << endl;
	}
	return 0;
}


