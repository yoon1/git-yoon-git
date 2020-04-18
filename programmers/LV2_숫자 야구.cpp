#include <iostream>
#include <memory.h>
#include <vector>

using namespace std;

bool isPossible(int score, int target, int strike, int ball) {

	return true;
}
int solution(vector<vector<int>> baseball) {
	int answer = 0;
	bool scoreBoard[1000] = { true };
	memset(scoreBoard, true, sizeof(scoreBoard));
	for (int i = 0; i < baseball.size(); i++) {
		int score = baseball[i][0];
		for (int j = 123; j <= 987; j++) {
			int strike = baseball[i][1];
			int ball = baseball[i][2];
			int arr_score[3];
			int arr_target[3];
			pair<int, int> cnt = make_pair(0,0);

			arr_score[0] = score / 100, arr_score[1] = (score % 100) / 10, arr_score[2] = (score % 10);
			arr_target[0] = j / 100, arr_target[1] = (j % 100) / 10, arr_target[2] = (j % 10);
			
			if ((arr_target[0] == 0 ||
				 arr_target[1] == 0 ||
				 arr_target[2] == 0)|| 
				(arr_target[0] == arr_target[1] ) ||
				(arr_target[1] == arr_target[2] ) ||
				(arr_target[0] == arr_target[2] ))
			{
				scoreBoard[j] = false;
				continue;
			}

			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					if (arr_score[i] == arr_target[j]) {
						if (i == j) cnt.first++;
						else cnt.second++;
					}
				}
			}
			if (cnt.first != strike || cnt.second != ball) {
				scoreBoard[j] = false;
			}
		}
	}
	for (int j = 123; j <= 987; j++) {
		if (scoreBoard[j])
			answer++;
	}
	return answer;
}

int main() {
	cout << solution({ {123, 1, 1}, {356, 1, 0}, {327, 2, 0}, {489, 0, 1} });
	return 0;
}