#include <iostream>
#include <sstream>
#include <set>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

vector<int> solution(string s) {
	vector<int> answer;
	vector<pair<int, string>> v;
	string number = "";
	int count = 1;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] != '{' && s[i] != '}' && s[i] != ',') {
			number += s[i];
		}
		if ( s[i] == '}' && number.length() != 0) {
			if (number[0] == ',')
				number = number.substr(1);
			v.push_back(pair<int, string>(count, number));
			number = "";
			count = 0;
		}
		if (s[i] == ',') {
			number = number + ",";
			count++;
		}
	}

	sort(v.begin(), v.end());
	
	number = "";
	set<string> m;
	for (int i = 0; i < v.size(); i++) {
		string t_number ="";
		string cur = v[i].second;
		for (int j = 0; j <  cur.length(); j++) {
			if (cur[j] != ',') {
				t_number += cur[j];
			}
			else {
				pair<set<string>::iterator, bool> pr = m.insert(t_number);
				stringstream ss(t_number);
				int n;
				ss >> n;
				if (pr.second) {
					answer.push_back(n);
					break;
				}
				t_number = "";
			}
		} 
		if (t_number.length() != 0) {
			pair<set<string>::iterator, bool> pr = m.insert(t_number);
			stringstream ss(t_number);
			int n;
			ss >> n;
			if (pr.second) {
				answer.push_back(n);
			}
		}
	}
	return answer;
}

int main() {
	//solution("{{2},{2,1},{2,1,3},{2,1,3,4}}");
	vector<int> result = solution("{{1,2,3},{2,1},{1,2,4,3},{2}}");
	return 0;
}
