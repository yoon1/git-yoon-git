#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main() {
	int T;
	cin >> T;
	string garbage;
	getline(cin, garbage);
	for (int testCase = 1; testCase <= T; testCase++) {
		string str;
		string buf;
		getline(cin, str);
		stringstream ss(str);
		vector<string> tokens;
		while (ss >> buf)
			tokens.push_back(buf);
		for (string token : tokens) {
			for (auto it = token.rbegin(); it != token.rend(); it++)
				cout << *it; 
			cout << " ";
		}
		cout << "\n";
	}
	return 0;

}