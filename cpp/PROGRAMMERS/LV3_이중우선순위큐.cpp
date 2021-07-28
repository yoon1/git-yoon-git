#include <iostream>
#include <algorithm>
#include <sstream>
#include <deque>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> operations) {
	vector<int> answer;
	deque<int> dq;
	for (int i = 0; i < operations.size(); i++) {
		string op = operations[i];
		stringstream ss(op.substr(2));
		int num;
		ss >> num;
		if (op[0] == 'I') {
			dq.push_back(num);
			sort(dq.begin(), dq.end());
		}
		else if(!dq.empty()) {
			if (num == -1) 
				dq.pop_front();
			else 
				dq.pop_back();
		}
	}
	if (dq.empty()) {
		answer.push_back(0);
		answer.push_back(0);
	}
	else {
		answer.push_back(dq.back());
		answer.push_back(dq.front());
	}
	return answer;
}

int main() {
	//vector<int> rslt = solution({ "I 16", "D 1" }); // 0 0을 리턴해야 해
	//vector<int> rslt = solution({"I 7", "I 5", "I -5", "D -1"}); // 0 0을 리턴해야 해
	vector<int> rslt = solution({ "I 16", "I -5643", "D -1", "D 1", "D 1", "I 123", "D -1"});
		for (auto it = rslt.begin(); it != rslt.end(); it++) {
		cout << *it << " " ;
	}
	return 0;
 }