#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> a, pair <int, int> b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	else {
		return a.second < b.second;
	}
}
int main() {
	
	int number = 0; // 회의의 수
	int minTime, maxTime = 0;
	int count = 0;
	int temp = 0;
	vector<pair<int, int > > v;

	cin >> number;
	
	for (int i = 0; i < number; i++) {
		cin >> minTime >> maxTime;
		v.push_back(pair<int,int>(minTime, maxTime));
	}

	sort(v.begin(), v.end(), compare);

	for(int i=0 ; i< v.size() ; i++) {
		if (temp <= v[i].first) {
			temp = v[i].second;
			count++;
		}
	}
	printf("%d", count);

	return 0;
}