#include <iostream>

using namespace std;

// 33 + 3 + 3 = 39
// 39 + 3 + 9 = 51
// 51 + 5 + 7;

bool nums[10001] = { false };
int self(int num) {
	int nextNum = num;
	while (num != 0) {
		nextNum += num % 10;
		num = num / 10;
	}
	if (nextNum <= 10000) {
		nums[nextNum] = true;
		return nextNum;
	}
	else
		return 0;
}

int main() {

	int cur;
	for (int i = 1; i <= 10000; i++) {
		cur = i;
		while (true) {
			cur = self(cur);
			if (cur == 0) break;
		}
	}
	for (int i = 1; i <= 10000; i++) {
		if (!nums[i])
			cout << i << endl;
	}
	return 0;
}
