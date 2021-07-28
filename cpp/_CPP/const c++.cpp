#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[]) {
	vector<int> a = { 1, 1, 2, 2, 2, 3, 1, 1, 1, 2, 2, 2, 2 };

	auto last = unique(a.begin(), a.end());

	// ���� Vector�� a���ʹ� ����X
	for (auto it = a.begin(); it != last; ++it) {
		cout << *it << ' ';     // 1 2 3 1 2
	}
	cout << endl;

	// ���� Vector�� a���͸� ������
	// ���� ������ �ߺ��� �����ϰ� �ʹٸ�
	// a.sort()�Ŀ� erase�� �Ѵ�!
	a.erase(last, a.end());
	for (int x : a) {
		cout << x << ' ';       // 1 2 3 1 2
	}
	cout << endl;
}
