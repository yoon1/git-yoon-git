#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
	int answer = 0;
	for (int i = 1; i < triangle.size(); i++) {
		for (int j = 0; j < triangle[i].size(); j++) {
			if (j == 0)
				triangle[i][j] = triangle[i][j] + triangle[i-1][j];
			else if (j == i)
				triangle[i][j] = triangle[i][j] + triangle[i - 1][j-1];
			else 
				triangle[i][j] = triangle[i][j] + max(triangle[i - 1][j], triangle[i - 1][j - 1]);
			answer = max(answer, triangle[i][j]);
		}
	}

	return answer;
}

int main() {
	cout << solution({{7}, {3, 8}, {8, 1, 0}, {2, 7, 4, 4}, {4, 5, 2, 6, 5}}) << endl;
	return 0;
}

