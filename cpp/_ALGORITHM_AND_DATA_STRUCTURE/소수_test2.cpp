#include <iostream>

int main() 
{
	double b, c;
	b = 123.123;

	printf("%b = %f\n", b);
	printf("%b = %10.5f\n", b);

	c = 1.1;

	printf("c = %f\n", c);
	printf("c = %10.5f\n", c);
	return 0;
}