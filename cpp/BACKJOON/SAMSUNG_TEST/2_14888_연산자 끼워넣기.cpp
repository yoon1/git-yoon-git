#include <iostream>
#include <limits.h>
#include <vector>
#include <algorithm>

using namespace std;

int calc(int a, int b, int op){
	switch (op) {
		case 1: return a + b;
		case 2: return a - b;
		case 3: return a * b;
		case 4: return a / b;
	}
}
int main() {
	int N;
	cin >> N;
	vector<int> nums(N);
	vector<int> ops;
	for(int i = 0; i < N; i++) cin >> nums[i]; // 입력받기
	int add, sub, mul, div;
	int minVal = INT_MAX, maxVal = INT_MIN;
	cin >> add >> sub >> mul >> div;
	for (int i = 0; i < add; i++) ops.push_back(1);
	for (int i = 0; i < sub; i++) ops.push_back(2);
	for (int i = 0; i < mul; i++) ops.push_back(3);
	for (int i = 0; i < div; i++) ops.push_back(4);
	do {
		int idx = 0;
		int cur = nums[idx++];
		for (int i = 0; i < ops.size(); i++) 
			cur = calc(cur, nums[idx++], ops[i]);
		maxVal = max(maxVal, cur);
		minVal = min(minVal, cur);
	} while (next_permutation(ops.begin(), ops.end()));
	cout << maxVal << "\n" << minVal;
	return 0;
}