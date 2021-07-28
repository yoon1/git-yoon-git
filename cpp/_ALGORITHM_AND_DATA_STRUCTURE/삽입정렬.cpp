#include <iostream>
using namespace std;
int main(void) {
	int i=0, j=8, temp;
	int array[10] = { 1, 10, 5, 8, 7, 6, 4, 3, 2, 9 };
	while (array[j]) {
		j--;
		printf("array[%d]  : %d\n", j, array[j]);
		//printf("%d ", i++);
	}
}