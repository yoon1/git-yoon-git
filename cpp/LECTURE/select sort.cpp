#include "pch.h"
#include <stdio.h>

int array[1001]; // 1000���� �Է� ���� �� �����ϱ�... (N + 1 ��ŭ �迭�� �ݴϴ�.)

int main()
{
	int number, i, j, min, index, temp;

	scanf_s("%d", &number);
	for (i = 0; i < number; i++) {
		scanf_s("%d", &array[i]);
	}
	for (i = 0; i < number; i++) {
		min = 1001; // ���밪�� 1000���� �۱� ������..
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
