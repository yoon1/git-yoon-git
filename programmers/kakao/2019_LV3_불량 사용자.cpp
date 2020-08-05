#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>

using namespace std;

set<vector<int>> s;
void backtracking(vector<string> user_id, vector<string> banned_id, vector<int> t, int state) {
	int idx = t.size();
	if (idx == banned_id.size()) {
		sort(t.begin(), t.end());
		s.insert(t);
		return;
	}
	for (int i = 0; i < user_id.size(); i++) {
		if ((state & (1 << i)) != 0) continue; // 방문 했었어?
		if (user_id[i].size() != banned_id[idx].size()) continue; // 사이즈 안같으면 100% 아니지..
		bool flag = true;
		for (int j = 0; j < banned_id[idx].size(); j++) {
			if (banned_id[idx][j] == '*') continue;
			if (user_id[i][j] != banned_id[idx][j]) {
				flag = false;
				break;
			}
		}
		if (flag) { // backtracking
			idx++; 
			state = state | (1 << i); // visited : true
			t.push_back(i);
			backtracking(user_id, banned_id, t, state);
			t.pop_back();
			state = state & ~(1 << i); // visited : false 
			idx--;
		}
	}
}
int solution(vector<string> user_id, vector<string> banned_id) {
	vector<int> t;
	backtracking(user_id, banned_id, t, 0);
	return s.size();
}
int main() {
	cout << solution({ "frodo", "fradi", "crodo", "abc123", "frodoc" }, { "*rodo", "*rodo", "******" }) << endl;
	return 0;
}