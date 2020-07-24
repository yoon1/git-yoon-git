#include <string>
#include <vector>

using namespace std;

string solution(string s) {
	string answer = "";
	bool up = true;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == ' ') 
			up = false;
		answer += up ? toupper(s[i]) : tolower(s[i]);
		up = up ? false : true;
	}
	return answer;
}