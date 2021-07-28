#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main(){
	long long a, b, c;
	vector<long long > v;

	cin >> a;
	for (long long i = 0; i < a; i++) {
		long long t;
		cin >> t;
		v.push_back(t);
	}
	cin >> b >> c;
	
	long long result = 0;
	for (long long i = 0; i < v.size(); i++) {
		result++;
		v[i] = v[i] - b;
		if (v[i] > 0) {
			result += ceil(v[i] * 1.0 / c);
		}

	}
	cout << result;

	return 0;
}

