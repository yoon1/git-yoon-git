#include <iostream>
#include <algorithm>

using namespace std;

bool isSosu(int num) {
	if (num < 2) return false;
	for (int i = 2; i < num; i++) {
		if (num % i == 0)
			return false;
	}
	return true;
}

int main() {
	int M, N;
	int minSosu = 99999;
	int result = 0;
	scanf_s("%d\n%d", &M, &N);

	for (int i = M; i <= N; i++) {
		if (isSosu(i)) {
			minSosu = min(minSosu, i);
			result += i;
		}
	}
	if (result == 0) {
		cout << "-1" << endl;
		return 0;
	}
	cout << result << endl;
	cout << minSosu << endl;
	return 0;
 }