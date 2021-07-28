#include<iostream>
#include <string>
#include <vector>

using namespace std;

string s;
int N, K;
vector<char> v;
int main() {
	cin >> N >> K;
	getline(cin, s);
	getline(cin, s);

	for (int i = 0; i < s.length(); i++) {
		char cur = s[i];
		while (K > 0 && !v.empty() && v.back() < cur) {
			v.pop_back();
			K--;
		}
		v.push_back(cur);
	}
	
	while (K--) v.pop_back();

	for (int i = 0; i < v.size(); i++)
		cout << v[i];
	return 0;
}