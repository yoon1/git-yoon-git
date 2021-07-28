#include <iostream>
#include <stdio.h>

using namespace std;

int main(){
	int t = 0 ;
	int a, b = 0 ;
	scanf_s("%d", &t);
	
	while (t--) {
		scanf_s("%d %d", &a, &b);
		
		printf("%d\n", a + b);
	}

	return 0;
}
// 입력을 미리 다 받아놓고 시작할 필요가 없다.


/*  별로 안좋은 방법.
int main () {
	int t;
	int a[100], b[100];
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%d %d", &a[i], &b[i]);
	}
	for (int i = 0; i < t; i++) {
		printf("%d\n", a[i] + b[i]);
	}
	return 0;
} */
