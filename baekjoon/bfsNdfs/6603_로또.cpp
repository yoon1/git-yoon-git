#include <iostream>
#include <vector>

using namespace std;

int K;
vector<int> v;
vector<int> result;

void backtracking(int index) {
	if (result.size() == 6) {
		for (int i = 0; i < result.size(); i++) 
			cout << result[i] << " ";
		cout << "\n";
		return;
	}
	// recursion
	for (int i = index; i < K; i++) {
		result.push_back(v[i]);
		backtracking(i + 1);
		result.pop_back();
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	while (cin >> K && K) {
		int S;
		v.clear();
		result.clear();
		for (int i = 0; i < K; i++) {
			cin >> S;
			v.push_back(S);
		}
		backtracking(0);
		cout << "\n";

	}
	return 0;
}
