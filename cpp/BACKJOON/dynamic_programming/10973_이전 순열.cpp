#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int N;
deque<int> dq;

void move_right(int idx) {
	while (idx < N ) {
		if (dq[idx] < dq[idx + 1])
			swap(dq[idx], dq[idx + 1]);
		else return;
		idx++;
	}
}
void move_left() {
	int idx = N - 1;
	bool flag = false;
	while (idx >= 0) {
		swap(dq[idx], dq[idx - 1]);
		idx--;
		if (dq[idx] < dq[idx + 1])
			return;
		else
			move_right(idx + 1);
	}
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int t;
		scanf("%d", &t);
		dq.push_back(t);
	}
	move_left();
	return 0;
}
