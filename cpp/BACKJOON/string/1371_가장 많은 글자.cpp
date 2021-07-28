#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

int main() {
	// 알파벳의 빈도수를 저장할 배열선언
	int arr[26] = { 0, };
	char tmp;
	int maxcnt = 0;
	// eof일 때 까지 while loop
	while (~scanf_s("%c", &tmp)) {
		if (isalpha(tmp)) {
			(arr[tmp - 'a'])++;
			// 가장 많이 나오는 문자가 지금까지 최대 몇번 나왔는지 저장.
			if (maxcnt < arr[tmp - 'a']) {
				maxcnt = arr[tmp - 'a'];
			}
		}
	}
	for (int i = 0; i < 26; i++) {
		// 가장 많이 나왔던 개수를 가지고 있는 문자(들)을 출력.
		if (maxcnt <= arr[i]) {
			cout << (char)(i + 'a');
		}
	}
}