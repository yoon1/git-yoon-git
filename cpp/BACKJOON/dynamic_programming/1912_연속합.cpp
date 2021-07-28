#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	int pre, cur;
	int maxTotal;
	int curTotal;
	cin >> N;
	cin >> pre;
	curTotal = pre;
	maxTotal = pre;
	for (int i = 1; i < N; i++) {
		cin >> cur;
		if (cur > pre && cur > 0) {
			curTotal = max(curTotal + cur, cur);
		}
		else {
			if(curTotal != 0) 
				maxTotal = max(curTotal, maxTotal);
			curTotal = 0;
		}
		pre = cur;
	}
	if (curTotal != 0)
		maxTotal = max(curTotal, maxTotal);
	cout << maxTotal;
	return 0;
}