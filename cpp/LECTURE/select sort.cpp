#include "pch.h"
#include <stdio.h>

int array[1001]; // 1000까지 입력 받을 수 있으니깐... (N + 1 만큼 배열을 줍니다.)

int main()
{
	int number, i, j, min, index, temp;

	scanf_s("%d", &number);
	for (i = 0; i < number; i++) {
		scanf_s("%d", &array[i]);
	}
	for (i = 0; i < number; i++) {
		min = 1001; // 절대값이 1000보다 작기 때문에..
		for (j = i; j < number; j++) {
			if (min > array[j]) {
				min = array[j];
				index = j;
			}
		}
		temp = array[i];
		array[i] = array[index];
		array[index] = temp;
	}
	for (i = 0; i < number; i++) {
		printf("%d ", array[i]);
	}

	return 0;
}
