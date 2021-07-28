#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool cmp(vector<int> a, vector<int> b) {
	return a[0] < b[0];
}

int solution(vector<vector<int>> routes) {
	int answer = 1;
	sort(routes.begin(), routes.end(), cmp);
	int cur = routes[0][1];
	for (int i = 0; i < routes.size(); i++) {
		int start = routes[i][0], end = routes[i][1];
		if (end < cur) {
			cur = end;
		}
		if (start > cur) {
			answer++;
			cur = end;
		}
	}
	return answer;
}

int main() {
	cout << solution({{-20, 15}, {-14, -5}, {-18, -13}, {-5, -3}}) << endl; 
	return 0;
}