#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define MAX_SIZE 1000
#define SWAP(x,y,t) ((t)=(x), (x)=(y), (y)=(t)) // 매크로 구현
void sort(int[], int); // selection sort

int main() {
	int i, n, list[MAX_SIZE];
	clock_t start, stop; // 시작 시간과 종료 시간
	double duration;

	printf("Enter the number of numbers to generate : ");
	scanf_s("%d", &n);
	if (n < 1 || n > MAX_SIZE) { // error
		fprintf(stderr, "Improper value of n\n");
		exit(1);
	}

	for(i = 0; i < n; i++){ // n개의 정수 random하게 생성
		list[i] = rand() % 1000;
		printf("%d ", list[i]);
	}

	start = clock();
	sort(list, n);
	stop = clock();
	printf("\n Sorted array : \n");
	for (i = 0; i < n; i++)  // 정렬된 정수 출력
		printf("%d ", list[i]);
	printf("\n");
	duration = ((double)(stop - start)) / CLOCKS_PER_SEC;
	printf(" %.2f\n", duration);

	return 0;
}
void sort(int list[], int n) {
	int i, j, min, temp;
	for (i = 0; i < n - 1; i++) { // list[i]부터 list[n-1]까지 정렬
		min = i; // 최소 값이 i에 있다고 일단 가정한다.
		for (j = i + 1; j < n; j++) // i위치 다음 모든 것에 대해
			if (list[j] < list[min]) // 더 작은 것이 있으면
				min = j; // 최소값을 이걸로
		SWAP(list[i], list[min], temp); // 최소값과 i의 내용 교체
	}
}