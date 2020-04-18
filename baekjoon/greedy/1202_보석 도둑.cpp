#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) a.first > b.first;
	else return a.second < b.second;

}
int main() {

	vector<pair<int, int>> jInfo; //보석
	vector<int> bInfo; // 가방
	int N, K, jWeight, jValue, bWeight = 0;
	
	cin >> N;
	cin >> K;
	for (int i = 0; i < N; i++) {
		cin >> jWeight >> jValue;
		jInfo.push_back(pair<int, int>(jWeight, jValue));
	}
	for (int i = 0; i < K; i++) {
		cin >> bWeight;
		bInfo.push_back(bWeight);
	}
	
	sort(jInfo.begin(), jInfo.end(), compare);
	sort(bInfo.begin(), bInfo.end());

	
	return 0;
} 