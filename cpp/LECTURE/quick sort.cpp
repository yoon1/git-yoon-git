#include "pch.h"
#include <stdio.h>

int data[1000001]; // 100만개 데이터.
int number = 0;

void quickSort(int *data, int start, int end) {
	if (start >= end) {
		return;
	}

	int key = start;
	int i = start + 1, j = end, temp;
	while (i <= j) {
		while (data[i] <= data[key]) {
			i++;
		}
		while (data[j] >= data[key] && j > start) { // 이 경우는 항상 엇갈렸을때.. 침범하지 못하도록 영역 제한.
			j--;
		}
		if (i > j) {
			temp = data[j];
			data[j] = data[key];
			data[key] = temp;
		}else {
			temp = data[i];
			data[i] = data[j];
			data[j] = temp;
		}
		quickSort(data, start, j - 1); // 한번 정렬을 마치고 나면 피벗을 기준으로 오른쪽과 왼쪽 값을 재정렬 시킨다.
		quickSort(data, j+1 , end);
	}
}
int main()
{
	scanf("%d", &number);

	for (int i = 0; i < number; i++) {
		scanf("%d", &data[i]);
	}

	quickSort(data, 0, number - 1);

	for (int i = 0; i < number; i++) {
		printf("%d\n", data[i]);
	}
	return 0;
}