#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

long long solution(int n, vector<int> times) {
	int tsize = times.size();
	long long m = *max_element(times.begin(), times.end());
	long long left = 1, right = m * n;
	long long mid;
	while (left <= right) { // left가 더 커지면 종료
		mid = (left + right) / 2;
		long long sum = 0;
		for (int i = 0; i < tsize; i++) 
			sum += (mid / times[i]);
		if (sum < n)
			left = mid + 1;
		else {
			right = mid - 1;
		}
	}
	return left;
}

int main() {
	cout << solution(6, { 7, 10 }) << endl;
	return 0;
}
