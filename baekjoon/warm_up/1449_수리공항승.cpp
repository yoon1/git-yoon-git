#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
	int N, L;
	vector<double> v;
	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		int t;
		cin >> t;
		v.push_back(t);
	}
	sort(v.begin(), v.end());

	pair<double, double> tape = { 0,0 };
	int rslt = 0;
	for (int i = 0; i < v.size(); i++) {
		if ( tape.first <= v[i] && tape.second >= v[i])
			continue;
		tape.first = v[i] - 0.5; // 0.5
		tape.second = tape.first + L; // 0.5
		rslt++;
	}
	cout << rslt << endl;
	return 0;
}