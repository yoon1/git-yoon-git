#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>

using namespace std;

bool isPossible(vector<string> t_user_id, vector<string> banned_id) {
	int n = t_user_id.size();
	
	vector<int> v;
	for (int i = 0; i < n; i++) {
		v.push_back(i);
	}
	do {
		vector<string> user_id;
		for (int i = 0; i < n; i++) {
			user_id.push_back(t_user_id[v[i]]);
		}
		vector<bool> check(banned_id.size(), false);

		int count = 0;

		for (int i = 0; i < user_id.size(); i++) {
			string cur_user_id = user_id[i];
			for (int j = 0; j < banned_id.size(); j++) {
				string cur_banned_id = banned_id[j];
				if (cur_banned_id.length() != cur_user_id.length())
					continue;
				if (check[j])
					continue;
				else {
					bool match_id = true;
					for (int n = 0; n < cur_banned_id.length(); n++) {
						if (cur_banned_id[n] != '*' && cur_banned_id[n] != cur_user_id[n]) {
							match_id = false;
							break;
						}
					}
					if (match_id) {
						count++;
						check[j] = true;
						if (count == banned_id.size()) 
							return true;
						break;
					}
				}
			}
			
		}
	}while (next_permutation(v.begin(), v.end()));

	return false;
}

int solution(vector<string> user_id, vector<string> banned_id) {
	int answer = 0;
	set<string> s;
	
	vector<int> t(user_id.size() - banned_id.size(), 0);
	for (int i = 0; i < banned_id.size(); i++)
		t.push_back(1);
	
	int n = 1;
	do {
		vector<string> t_user_id;
		for (int i = 0; i < user_id.size(); i++) {
			if (t[i] == 1)
				t_user_id.push_back(user_id[i]);
		}
		if (isPossible(t_user_id, banned_id)) {
			answer++;
		}
	} while (next_permutation(t.begin(), t.end()));

	return answer;
}

int main() {
	//cout << solution({ "frodo", "fradi", "crodo", "abc123", "frodoc" }, { "fr*d*", "abc1**" }) << endl;
	//cout << solution({ "frodo", "fradi", "crodo", "abc123", "frodoc" }, { "*rodo", "*rodo", "******" }) << endl;
	cout << solution({ "frodo", "fradi", "crodo", "abc123", "frodoc" }, { "fr*d*", "*rodo", "******", "******" }) << endl;

	//บคลอ
	return 0;
}