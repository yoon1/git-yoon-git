#include <iostream>
#include <algorithm>
#include <deque>
#include <string>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int testCase, N;
	cin >> testCase;
	for (int t = 0; t < testCase; t++) {
		cin >> N;
		deque<long long> dq;
		for (int i = 0; i < N; i++) {
			char op;
			long long num;
			cin >> op >> num;
			if (op == 'I') {
				dq.push_back(num);
				sort(dq.begin(), dq.end());
			}
			else if (!dq.empty()) {
				if (num == -1)
					dq.pop_front();
				else
					dq.pop_back();
			}
		}
		if (dq.empty()) {
			cout << "EMPTY\n";
		}
		else {
			cout << dq.back() << " " << dq.front() << "\n";
		}
	}
}