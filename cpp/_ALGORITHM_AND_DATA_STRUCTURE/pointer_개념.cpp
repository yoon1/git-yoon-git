#include <stdio.h>

int main()
{
	int x = 1;
	int* y = &x;

	printf("%d\n", *y);
	printf("%d\n", y);
	printf("%d\n", &x);
	printf("%d\n", x);

	return 0;
}