#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define MAX_SIZE 1000
#define SWAP(x,y,t) ((t)=(x), (x)=(y), (y)=(t)) // ��ũ�� ����
void sort(int[], int); // selection sort

int main() {
	int i, n, list[MAX_SIZE];
	clock_t start, stop; // ���� �ð��� ���� �ð�
	double duration;

	printf("Enter the number of numbers to generate : ");
	scanf_s("%d", &n);
	if (n < 1 || n > MAX_SIZE) { // error
		fprintf(stderr, "Improper value of n\n");
		exit(1);
	}

	for(i = 0; i < n; i++){ // n���� ���� random�ϰ� ����
		list[i] = rand() % 1000;
		printf("%d ", list[i]);
	}

	start = clock();
	sort(list, n);
	stop = clock();
	printf("\n Sorted array : \n");
	for (i = 0; i < n; i++)  // ���ĵ� ���� ���
		printf("%d ", list[i]);
	printf("\n");
	duration = ((double)(stop - start)) / CLOCKS_PER_SEC;
	printf(" %.2f\n", duration);

	return 0;
}
void sort(int list[], int n) {
	int i, j, min, temp;
	for (i = 0; i < n - 1; i++) { // list[i]���� list[n-1]���� ����
		min = i; // �ּ� ���� i�� �ִٰ� �ϴ� �����Ѵ�.
		for (j = i + 1; j < n; j++) // i��ġ ���� ��� �Ϳ� ����
			if (list[j] < list[min]) // �� ���� ���� ������
				min = j; // �ּҰ��� �̰ɷ�
		SWAP(list[i], list[min], temp); // �ּҰ��� i�� ���� ��ü
	}
}