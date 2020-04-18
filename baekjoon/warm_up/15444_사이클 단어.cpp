#include <iostream>
#include <algorithm>
#include <set>
#include <string>

using namespace std;
int main()
{
	set<string> m;
	int N;
	int cnt = 0;
	string str;
	cin >> N;
	for (int i = 0; i < N; i++) {
		bool exists = false;
		cin >> str;
		for (int j = 0; j < str.length(); j++) {
			str = str.substr(1, str.length() - 1) + str.substr(0, 1);
			auto it = find(m.begin(), m.end(), str);
			if (it != m.end()) {
				exists = true;
				break;
			}
		}
		if (!exists) 
			m.insert(str);
	}
	cout << m.size();
	return 0;
}