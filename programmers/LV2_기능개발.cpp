#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	queue<double> q;
	for (int i = 0; i < progresses.size(); i++)
		//q.push(make_pair(progresses[i], speeds[i]));
		q.push((100 - progresses[i]) / speeds[i]);

	while (!q.empty()) {
		int count = 1;
		double t = q.front();
		q.pop();
		while (!q.empty() && t >= q.front()) {
			count++;
			q.pop();
		}
		answer.push_back(count);
	}
	
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << endl; 
	}
	
	return answer;
}

int main() {

	solution({ 93, 30, 55 }, { 1,30,5 });

	return 0;
}