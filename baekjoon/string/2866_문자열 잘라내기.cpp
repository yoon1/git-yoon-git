#include <iostream>
#include <algorithm>
#include <set>
#include <string>
#include <memory>

using namespace std;

int main() {
	int answer = 0;
	int R, C;
	set<string> s;
	string str1;
	string str2;
	cin >> R >> C;
	cin >> str1;
	for (int i = 1; i < R; i++) {
		cin >> str2;
		for (int j = 0; j < C; j++) {
			string str = "";
			str += str1[j];
			str += str2[j];
			auto it = find(s.begin(), s.end(), str);
			if (it != s.end()) {
				cout << answer << endl;
				return 0;
			} else {
				s.insert(str);
			}
		}
		if ( R > 2) answer++;
	}
	cout << answer << endl;
	return 0;
}
