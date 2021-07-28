#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(int m, int n, int s, vector<vector<int>> time_map) {
	int move_distance = 0;
	int sum_of_talk_time = 0;

	vector<int> answer(2);
	answer[0] = move_distance;
	answer[1] = sum_of_talk_time;

	return answer;
}

int main() {
	solution(3, 3, 150, { {0, 2, 99}, {100, 100, 4}, {1, 2, 0} });

	return 0;
}