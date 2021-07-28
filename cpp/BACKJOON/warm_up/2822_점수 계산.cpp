#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp_first(pair<int, int> a, pair<int, int> b) {
	return a.first > b.first;
}

bool cmp_second(pair<int, int> a, pair<int, int> b) {
	return a.second < b.second;
}

int main() {
	vector<pair<int, int>> v;
	int total = 0;
	int num;
	for (int i = 1; i <= 8; i++) {
		cin >> num;
		v.push_back(make_pair(num,i));
		total += num;
	}
	sort(v.begin(), v.end(), cmp_first);
	
	for (int i = 0; i < 3; i++) {
		total = total - v.back().first;
		v.pop_back();
	}
	cout << total << endl;
	sort(v.begin(), v.end(), cmp_second);
	for (int i = 0; i < 5; i++) {
		cout << v[i].second << " ";
	}
	
	return 0;
 }