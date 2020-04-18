#include <iostream>
#include <deque>

using namespace std;

deque<int> dq;
deque<int> numberList;

int N, M;

int targetNumber = 0;
int total = 0;

void popDq() {
	dq.pop_front();
}

void shiftLeftDq(int n) {
	for (int i = 0; i < n; i++) {
		dq.push_back(dq.front());
		dq.pop_front();
		total++;
	}
}

void shiftRightDq(int n) {
	for (int i = 0; i < n; i++) {
		dq.push_front(dq.back());
		dq.pop_back();
		total++;
	}
}

void popTargetNumber(int targetNumber) {
	int targetPos = 0; ;
	for (int i = 0; i < dq.size(); i++) {
		if (dq.at(i) == targetNumber) targetPos = i + 1;
	}
	if (targetPos - 1 <= dq.size() / 2) shiftLeftDq(targetPos - 1);
	else shiftRightDq(dq.size() - (targetPos - 1));
	
	popDq();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		dq.push_back(i);
	}

	for (int i = 0; i < M; i++) {
		cin >> targetNumber;
		popTargetNumber(targetNumber);
	}

	cout << total;
	return 0;
}