#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

int main() {
	// ���ĺ��� �󵵼��� ������ �迭����
	int arr[26] = { 0, };
	char tmp;
	int maxcnt = 0;
	// eof�� �� ���� while loop
	while (~scanf_s("%c", &tmp)) {
		if (isalpha(tmp)) {
			(arr[tmp - 'a'])++;
			// ���� ���� ������ ���ڰ� ���ݱ��� �ִ� ��� ���Դ��� ����.
			if (maxcnt < arr[tmp - 'a']) {
				maxcnt = arr[tmp - 'a'];
			}
		}
	}
	for (int i = 0; i < 26; i++) {
		// ���� ���� ���Դ� ������ ������ �ִ� ����(��)�� ���.
		if (maxcnt <= arr[i]) {
			cout << (char)(i + 'a');
		}
	}
}