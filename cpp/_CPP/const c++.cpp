#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[]) {
	vector<int> a = { 1, 1, 2, 2, 2, 3, 1, 1, 1, 2, 2, 2, 2 };

	auto last = unique(a.begin(), a.end());

	// 원래 Vector인 a벡터는 변경X
	for (auto it = a.begin(); it != last; ++it) {
		cout << *it << ' ';     // 1 2 3 1 2
	}
	cout << endl;

	// 원래 Vector인 a벡터를 변경함
	// 만약 완전히 중복을 제거하고 싶다면
	// a.sort()후에 erase를 한다!
	a.erase(last, a.end());
	for (int x : a) {
		cout << x << ' ';       // 1 2 3 1 2
	}
	cout << endl;
}
