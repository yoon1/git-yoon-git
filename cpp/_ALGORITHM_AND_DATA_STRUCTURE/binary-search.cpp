#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int compare(int x, int y)
{
	// x와 y를 비교하여 경우에 따라 -1, 0, 1을 출력
	if (x < y) return -1;
	else if (x == y) return 0;
	else return 1;
}

int binsearch(int list[], int searchnum, int left, int right)
{
	/*search list[0] <= list[1] <= ... <= list[n-1] for searchnum.
	Return its position if found. Otherwise return -1 */
	int middle;
	if (left <= right) {
		middle = (left + right) / 2;
		switch (compare(list[middle], searchnum)) {
		case -1: return binsearch(list, searchnum, middle + 1, right);
		case 0: return middle;
		case 1: return binsearch(list, searchnum, left, middle - 1);
		}
	}
	return -1;
}

int main() {
	int lst[10] = { 1,2,5,3,9,8,6,7,10,12 };
	int idx = binsearch(lst, 8, 0, 10);
	printf("%d", idx);
	return 0;
}