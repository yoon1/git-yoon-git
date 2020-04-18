#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
	int answer = 0;
	
	for (int i = 1; i < triangle.size(); i++) {
		for (int j = 0; j < triangle[i].size(); j++) {
			if (j == 0)
				triangle[i][j] = triangle[i][j] + triangle[i - 1][j];
			else if (j == i)
				triangle[i][j] = triangle[i][j] + triangle[i - 1][j - 1];
			else
				triangle[i][j] = triangle[i][j] + max(triangle[i - 1][j], triangle[i - 1][j - 1]);
			answer = max(answer, triangle[i][j]);
		}
	}

	return answer;
}

int main() {
	vector<vector<int>> v;
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		vector<int> element;
		for (int j = 1; j <= i; j++)  {
			int t;
			cin >> t;
			element.push_back(t);
		}
		v.push_back(element);
	}
	
	cout << solution(v) << endl;
	return 0;
}