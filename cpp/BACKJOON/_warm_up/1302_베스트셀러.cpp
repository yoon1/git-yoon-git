#include <iostream>
#include <string>
#include <map>

using namespace std;

int N;
map<string, int> m;
int main() {
	cin >> N; 
	for (int i = 0; i < N; i++) {
		string book; cin >> book;
		if ( m.find(book) == m.end()) 
			m[book] = 1;
		else 
			m[book]++;
	}
	pair<string, int> ret = { "",0 };
	for (auto it = m.begin(); it != m.end(); it++)
		if (ret.second < it->second)
			ret = *it;

	cout << ret.first << endl;
	return 0;
}