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
		// memset 함수는 어떤 메모리의 시작점부터 연속된 범위를 어떤값으로 (바이트단위) 모두 지정하고 싶을 때 사용하는 함수.
		/*  
			void * memset(void * ptr, int value, size_t num);
			- ptr : 채우고자 하는 메모리의 시작 포인터(시작 주소)
			- value : 메모리에 채우고자 하는 값, int형이지만 내부에서는 unsigned char(1byte) 로 변환되어서 저장된다.
			- num : 채우고자 하는 바이트의 수. 즉, 채우고자 하는 메모리의 크기.
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