#include "pch.h"
#include <stdio.h>

int n;
int a[10001];

int main(void) {
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) {
		int x;
		scanf_s("%d", &x);
		a[x]++;
	}

	for (int i = 0; i < 10001; i++) {
		while (a[i] != 0) {
			printf("%d\n", i);
			a[i]--;
		}
	}
}