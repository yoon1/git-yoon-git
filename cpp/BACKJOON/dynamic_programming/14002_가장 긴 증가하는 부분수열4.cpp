#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int T[1001];
int len = 0;

int main() {
	cin >> N;
	vector<int> v;
	for (int i = 0; i < N; i++) {
		int t;
		cin >> t;
		int a = lower_bound(T, T + 1001, t) - T;
		if (a == len) {
			len++;
			idx = i;
		}
	}

	cout << arr.size() << endl;
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}
	return 0;
}