// 시간초과 개선 필요

#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool promising(int M, int x, vector<int> budgets) {
	for (int i = 0; i < budgets.size(); i++) {
		int budget = x > budgets[i] ? budgets[i] : x;
		M = M - budget;
		if (M < 0)
			return false;
	}
	return true;
}
int solution(vector<int> budgets, int M) {
	int answer = 0;
	int left = 1;
	int right = M;
	int mid = (left + right) / 2;
	while (left <= right) {
		mid = (left + right) / 2;
		if (promising(M, mid, budgets)) {
			if (answer < mid)
				answer = mid;
			left = mid + 1;
		}
		else
			right = mid - 1;
	}
	return answer;
}

int main() {
	cout << solution({100, 100, 100, 110}, 100) << endl;
	return 0;
}