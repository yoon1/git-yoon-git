#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int N;
	vector<int> v;
	int current = 0;
	int result = 0;
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		int K;
		cin >> K;
		v.push_back(K);
	}
	
	sort(v.begin(), v.end());

	for (int i = 0; i < N; i++) {
		current = v[i] * (v.size() - i);
		if (current > result) result = current;
	}
	cout << result;

	return 0;

}