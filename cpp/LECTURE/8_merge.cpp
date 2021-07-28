#include "pch.h"
#include <stdio.h>

#define number 8
int sorted[8]; // 정렬 배열은 반드시 전역 변수로 만들어 주어야 한다.
// 정렬을 위해 필요한 추가 배열.

void merge(int a[], int m, int middle, int n) {
	int i = m;
	int j = middle + 1;
	int k = m; // 실제로 i와 동일선상에서 시작하게 되니까요 :-)

	//작은 순서대로 배열에 삽입.
	while (i <= middle && j <= n) {// 항상 i와 j를 비교해서 더 작은 값을 k에 넣어준다.
		if (a[i] <= a[j]) {
			sorted[k] = a[i];
			i++;
		}
		else {
			sorted[k] = a[j];
			j++;
		}
		k++; // k값을 증가시켜서 다음 값을 받을 수 있게 해주는거에요.
	}
	//i 가 먼저 끝나면 남은 j를 다 넣고,  j가 먼저 끝나면 남은 i를 다 넣음.

	if (i > middle) {
		for (int t = j; t <= n; t++) {
			sorted[k] = a[t];
			k++;
		}
	} else {
			for (int t = i; t <= middle; t++) {
				sorted[k] = a[t];
				k++;
		}
	}
	// 정렬된 배열을 삽입.
	for (int t = m; t <= n; t++) {
		a[t] = sorted[t]; 
	}
}

//두 갈래로 분할 후 반복해서 병합을 하니까 재귀 함수를 쓰는 게 좋겠죠.
void mergeSort(int a[], int m, int n) {
	if (m < n) {
		int middle = (m + n) / 2;
		mergeSort(a, m, middle); // 왼쪽
		mergeSort(a, middle + 1, n); // 오른쪽
		merge(a, m, middle, n); // 나중에 합치는 것.
	}
}

int main(void) {
	int array[number] = { 7,6,5,8,3,5,9,1 };
	mergeSort(array, 0, number - 1);
	for (int i = 0; i < number; i++) {
		printf("%d ", array[i]);
	}
}