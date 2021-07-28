#include <iostream>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;
	vector<int> student(n+1,1);

	for (int i = 0; i < lost.size(); i++) {
		student[lost[i]]--;
	}
	for (int i = 0; i < reserve.size(); i++) {
		student[reserve[i]]++;
	}
	for (int i = 1; i < student.size(); i++) {
		cout << student[i] << " ";
	}
	cout << endl;
	for (int i = 1; i < student.size(); i++) {
		if (student[i] == 0) {
			if (i - 1 >= 0 && student[i - 1] >= 2) {
				answer++;
				student[i - 1]--;
				continue;
			}
			if (i + 1 < student.size() && student[i + 1] >= 2) {
				answer++;
				student[i + 1]--;
				continue;
			}
		}
		else answer++;
	}

	for (int i = 1; i < student.size(); i++) {
		cout << student[i] << " ";
	}
	cout << endl;
	return answer;
}

int main() {
	//cout << solution(5, { 2,4 }, { 1,3,5 }) << endl;
	//cout << solution(5, { 2,4 }, { 3 }) << endl;
	//cout << solution(3, { 1,2 }, { 2,3 }) << endl;
	cout << solution(5, { 2,4 }, { 3,5 }) << endl;
	return 0;
}
