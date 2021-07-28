#include <iostream>
#include <vector>
using namespace std;

int main() {
	std::ios_base::sync_with_stdio(false);
	int N, K;
	int A;
	int count = 0;
	vector <int> v;
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> A;
		v.push_back(A);
	}

	for (int i = v.size() - 1; i >= 0; i--) {	
		if (v[i] > K) { 
			continue;
		}
		count += K / v[i];
		K = K % v[i];
	}
	cout << count << endl;
	return 0;
}