//C++의 sort함수를 이용해볼게요.
// 13개만ㅋ큼의 문자열이 들어오네요.
#include "pch.h"
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string a[20000] ; // 20000개의 문자열 까지 받을 수 있게 만들어줘요.
int n;

int getSum(string a) {
	int length = a.length(), sum = 0;
	for (int i = 0; i < length; i++) {
		//숫자인 경우에만 더합니다.
		if (a[i] - '0' <= 9 && a[i] - '0' >= 0) {
			sum += a[i] - '0';
		}
	}
	return sum;
}

// sort함수의 3번째 인자값으로 들어가는 것.
bool compare(string a, string b) {
	// 길이가 짧은 순서 우선
	if (a.length() < b.length()) { // 어떤 문자열과 비교했을 때 길이로 인한 우선 순위가 높은가?낮은가?
		return 1;
	}else if (a.length() > b.length()) {
		return 0;
	}
	else {// 길이가 같은 경우
		int aSum = getSum(a);
		int bSum = getSum(b);
		if (aSum != bSum) {
			return aSum < bSum;
		}
		else {
			return a < b;
		}
	}
}

int main() { 
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n, compare);
	for (int i = 0; i < n; i++) {
		if (i > 0 && a[i] == a[i - 1]) {
			continue;
		}
		else {
			cout << a[i] << '\n';
		}
	}
}
