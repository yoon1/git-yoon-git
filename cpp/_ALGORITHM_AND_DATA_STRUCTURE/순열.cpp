#include <iostream>
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))

void perm(char *list, int i, int n)
// list[i]에서 list[n]까지의 원소로 구성된 모든 순열 출력
// {a, b, c, d}의 경우 초기 호출 = perm(list, 0, 3)
{
	int j, temp;
	if (i == n) { // 단 하나의 순열만 존재. 그냥 출력하자…
		for (j = 0; j <= n; j++)
			printf("%c", list[j]);
		printf("\n");
	}
	else { // 하나 이상의 순열 존재. 재귀적으로 출력
		for (j = i; j <= n; j++) {
			SWAP(list[i], list[j], temp);
			perm(list, i + 1, n);
			SWAP(list[i], list[j], temp);
		}
	}
}

int main() {
	char list[] = { 'a','b','c','d' };
	perm(list, 0, 3);
	return 0;
}