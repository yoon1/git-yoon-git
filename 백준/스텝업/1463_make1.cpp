#include <iostream>
#include <algorithm>
using namespace std;

class makeOne {
private:
	int n;
	int arr[100001];

public:
	void setNum() {
		cin >> n;
		memset(arr, 0, sizeof(int) * (n + 1)); 
		// memset �Լ��� � �޸��� ���������� ���ӵ� ������ ������� (����Ʈ����) ��� �����ϰ� ���� �� ����ϴ� �Լ�.
		/*  
			void * memset(void * ptr, int value, size_t num);
			- ptr : ä����� �ϴ� �޸��� ���� ������(���� �ּ�)
			- value : �޸𸮿� ä����� �ϴ� ��, int�������� ���ο����� unsigned char(1byte) �� ��ȯ�Ǿ ����ȴ�.
			- num : ä����� �ϴ� ����Ʈ�� ��. ��, ä����� �ϴ� �޸��� ũ��.
		*/
	}

	void solution() {
		arr[1] = 0;

		for (int i = 2; i <= n; i++) {
			arr[i] = arr[i - 1] + 1;
			if (i % 2 == 0) {
				arr[i] = min(arr[i], arr[i / 2] + 1);
			}
			if (i % 3 == 0) {
				arr[i] = min(arr[i], arr[i / 3] + 1);
			}
		}
	}

	void printMin() {
		cout << arr[n];
	}
};
int main() {
	makeOne one;
	one.setNum();
	one.solution();
	one.printMin();
	return 0;
}