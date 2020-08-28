#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
	int answer = s.length();
	for (int i = 1; i <= (s.length() / 2); i++) {
		string result = "";
		string pre = s.substr(0, i);
		int count = 1;
		for (int j = i; j <= s.length(); j = j + i) {
			if (pre == s.substr(j, i)) {
				count++;
			}
			else {
				if (count == 1) {
					result += pre;
				}
				else {
					result += (to_string(count) + pre);
				}
				pre = s.substr(j, i);
				count = 1;
			}
		}
		answer = min(answer, (int)result.length());
	}

	return answer;
}

int main() {
	cout << solution("aabbacccc") << endl;
	return 0;
}
 