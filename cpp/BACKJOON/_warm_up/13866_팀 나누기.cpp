#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> team;
int main() {
	for (int i = 0; i < 4; i++) {
		int t; cin >> t;
		team.push_back(t);
	}
	sort(team.begin(), team.end());

	cout << abs((team[3] + team[0] ) - (team[2] + team[1]));

	return 0;
}