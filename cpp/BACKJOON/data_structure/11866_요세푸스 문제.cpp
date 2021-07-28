#include <iostream>
#include <string>
#include <algorithm>
#include <deque>

using namespace std;
int main() {
	int N, K;
	cin >> N >> K;
	deque<int> q;
	deque<int> t;
	for (int i = 1; i <= N; i++)
		q.push_back(i);

	do {
		int distance = (K - 1) % q.size();
		rotate(q.begin(), q.begin() + distance, q.end());
		t.push_back(q.front());
		q.pop_front();
	} while (!q.empty());

	string result = "<";
	for (int i = 0; i < t.size(); i++) {
		result += to_string(t[i]);
		if (i != t.size() - 1) result += ", ";
	}
	result += ">";
	cout << result << "\n";

	return 0;
}