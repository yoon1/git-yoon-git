#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(int a, int b) {
	return a > b;
}
int main() {
	vector<int> v;
	int N = 0;
	int result = 0;
	cin >> N; // input

	for (int i = 0; i < N; i++) {
		int P = 0;
		cin >> P;
		v.push_back(P);
	}
	sort(v.begin(), v.end(), compare);
	
	for (int i = 0; i < N; i++) {
		result += (i + 1) * v[i];
	}
	cout << result << endl;
	return 0;
}