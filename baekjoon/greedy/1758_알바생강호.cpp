#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
	int N;
	long long total = 0;
	vector <int> v;
	scanf_s("%d", &N, sizeof(N));
	for (int i = 1; i <= N; i++) {
		int t;
		scanf_s("%d", &t, sizeof(t));
		v.push_back(t);
	}
	sort(v.begin(), v.end(), greater<int>());
	for (int i = 0; i < v.size(); i++ ){
		int t = v[i] - i;
		if (t > 0)
			total += t;
	}
	cout << total;
	return 0;
}