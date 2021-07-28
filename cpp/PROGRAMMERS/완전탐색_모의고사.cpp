#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#define giveUpperCycle1 5
#define giveUpperCycle2 8
#define giveUpperCycle3 10
#define okCountNumber 3
using namespace std;

vector<int> solution(vector<int> answers) {
	vector<int> answer;
	int giveUpper1[giveUpperCycle1] = { 1,2,3,4,5 };
	int giveUpper2[giveUpperCycle2] = { 2,1,2,3,2,4,2,5 };
	int giveUpper3[giveUpperCycle3] = { 3,3,1,1,2,2,4,4,5,5 };
	int okCount[3] = {};
	int maxCount = 0;
	
	for (int i = 0; i < answers.size(); i++) {
		if (giveUpper1[i % giveUpperCycle1] == answers[i]) { okCount[0]++; };
		if (giveUpper2[i % giveUpperCycle2] == answers[i]) { okCount[1]++; };
		if (giveUpper3[i % giveUpperCycle3] == answers[i]) { okCount[2]++; };
	}
	
	maxCount = max(okCount[0], okCount[1]);
	maxCount = max(maxCount, okCount[2]);

	for (int i = 0; i < okCountNumber; i++) {
		if (okCount[i] == maxCount) answer.push_back(i+1);
	}

	for (int ans : answer) {
		cout << ans << ","; 
	}
	return answer;

}

int main() {
	//solution({1, 2, 3, 4, 5});
	solution({ 1, 3, 2, 4, 2 });
	return 0;
}