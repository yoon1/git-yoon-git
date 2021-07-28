#include <iostream>

int main() {
	int i = 1;
	int num = 2;

	while (i <= 10) {
		int j = 2;
		while (j < num) {
			if (num % j == 0)
				break;
			j++;
		}
		if (num == j)
		{
			printf("%d번째 소수는 %d\n", i, num);
			i++;
		}
		num++;
	}
	printf("\n");
	return 0;
}