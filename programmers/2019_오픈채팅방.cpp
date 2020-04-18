#include <iostream>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> record) {
	vector<string> answer;
	vector<string>::iterator vi;
	map<string, string> m;
	vector<pair<string, string>> t;

	for (vi = record.begin(); vi != record.end(); vi++) {
		vector <string> tokens;
		string buf;
		stringstream ss(*vi);
		ss >> buf;
		string state = buf;
		ss >> buf;
		string id = buf;
		t.push_back(make_pair(state, id));
		if (state != "Leave") {
			ss >> buf;
			string nickname = buf;
			m[id] = nickname;
		}
	}
	
	for (int i = 0; i < t.size(); i++) {
		string nickname = m[t[i].second];
		string state = "";
		if (t[i].first == "Enter") { 
			answer.push_back(nickname + "´ÔÀÌ µé¾î¿Ô½À´Ï´Ù.");  
		}
		else if (t[i].first == "Leave") {
			answer.push_back(nickname + "´ÔÀÌ ³ª°¬½À´Ï´Ù.");
		}
	}
	return answer;
}

int main()
{
	solution({ "Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan" });
}