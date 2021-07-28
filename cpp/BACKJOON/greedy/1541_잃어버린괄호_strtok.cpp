#include <cstdio>
#include <cstring>
#include <cstdlib>

char cal[51];
char ca[51];
char* ptr;
int ret, i = 0;

int calculate(char * str) {
	int r = 0;
	char* ptr2;
	ptr2 = strtok(str, "+=");
	r += atoi(ptr2);
	while (ptr2 = strtok(NULL, "+=")) {
		r += atoi(ptr2);
	}
	return r;
}

int main() {
	scanf("%s", cal);
	ptr = strtok(cal, "-");
	strcpy(ca, ptr);
		ptr = strtok(NULL, "");
	ret = calculate(ca);
	if (ptr != NULL)
		ret -= calculate(ptr);
	printf("%d", ret);
	return 0;
}