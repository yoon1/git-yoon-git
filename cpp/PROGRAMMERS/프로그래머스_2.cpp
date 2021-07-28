#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;


vector<int> solution(vector<int> heights) {
	vector<int> answer;

	answer.resize(heights.size());
	for (int i = heights.size() - 1; i >= 0 ; i--) {
		for (int j = i - 1; j >= 0; j--) {
			if (heights[i] < heights[j]) {
				answer[i] = j + 1;
				break;
			}
		}
	}

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << " ";
	}
	cout << endl;
	return answer;

}
int main()
{
	solution({ 6, 9, 5, 7, 4 });
	solution({3, 9, 9, 3, 5, 7, 2});
	solution({ 1, 5, 3, 6, 7, 6, 5 });

	
}