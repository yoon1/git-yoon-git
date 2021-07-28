#include <stdio.h>
#include <string.h>

using namespace std;

int main() {
	char str[40];
	int n, M, numberSet = 0;
	scanf("%d", &M);
	for(int i=0; i < M; i++){
		scanf("%s", str);
		if (!strcmp(str, "all") )
			numberSet = (1 << 21) - 1;
		else if (!strcmp(str, "empty"))
			numberSet = 0;
		else {
			scanf("%d", &n);
			if (!strcmp(str, "add"))
				numberSet |= (1 << n);
			else if (!strcmp(str, "check"))
				printf("%d\n", !(numberSet & (1 << n)) ? 0 : 1);
			else if (!strcmp(str, "remove"))
				numberSet &= ~(1 << n);
			else if (!strcmp(str, "toggle"))
				numberSet ^= (1 << n);
		}
	}
	return 0;
}
