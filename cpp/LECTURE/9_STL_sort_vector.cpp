#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
bool compare(pair<string, pair<int, int> > a,
	pair<string, pair<int, int> > b) {
	if (a.second.first == b.second.first) {
		return a.second.second > b.second.second;
	}
	else {
		return a.second.first > b.second.first;
	}
}
int main() {
	vector<pair <string, pair<int, int> > > v;
	v.push_back(pair <string, pair<int, int> > ("나동빈", pair<int,int> (90, 19961222)));
	v.push_back(pair <string, pair<int, int> >("이태일", pair<int, int>(79, 19930518)));
	v.push_back(pair <string, pair<int, int> >("박한울", pair<int, int>(79, 19930203)));
	v.push_back(pair <string, pair<int, int> >("이상욱", pair<int, int>(90, 19901222)));
	v.push_back(pair <string, pair<int, int> >("강종구", pair<int, int>(88, 19921222)));
	

	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].first << ' ';
	}

	return 0;
}