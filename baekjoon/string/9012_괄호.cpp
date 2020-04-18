#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
	std::ios_base::sync_with_stdio(false);
	string str;
	int N;
	cin >> N;
	
	for (int i = 0; i < N; i++) {
	
		pair<int, int> count;
		cin >> str;
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == '(') count.first++;
			if (str[i] == ')') count.second++;
			if (count.second > count.first) {
				cout << "NO\n";
				break;
			}
		}
		if (count.second == count.first) cout << "YES\n";
		else if (count.second < count.first) cout << "NO\n";
	}

	return 0;
}

/* 짝이 맞아야 함 일단  */
