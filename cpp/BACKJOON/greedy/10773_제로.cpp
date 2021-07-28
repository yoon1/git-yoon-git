#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N;
	int t;
	long long total = 0;
	vector<int> v;
	scanf_s("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf_s("%d", &t);
		if (t == 0)
			v.pop_back();
		else v.push_back(t);
	}
	for (int i = 0; i < v.size(); i++) 
		total += v[i];
	cout << total;
	return 0;
}
