#include <iostream>
#include <vector>
#include <string>
#include <deque>

using namespace std;



int solution(vector<int> priorities, int location) {
	int answer = 0;
	deque<pair<int, int>> dq;
	for ( int i=0; i < priorities.size(); i++) {
		dq.push_back(make_pair(i, priorities[i]));
	}

	while (!dq.empty()) {
		pair<int, int> temp = make_pair(dq.front().first, dq.front().second);
		bool bigPriority = false;
		for(int i = 0; i < dq.size(); i++) {
			if (temp.second < dq[i].second)
			{
				bigPriority = true;
				dq.pop_front();
				dq.push_back(temp);
				break;
			}
		}

		if (!bigPriority) {
			dq.pop_front();
			answer++;
			if (temp.first == location) {
				return answer;
			}
		}
	}
	return answer;
}

int main() {
	cout << solution({ 2, 1, 3, 2 }, 2);
	cout << solution({1, 1, 9, 1, 1, 1}, 0);
	return 0;
}