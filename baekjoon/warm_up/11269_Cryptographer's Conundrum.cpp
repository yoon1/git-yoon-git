#include <stdio.h>
#include <string.h>
#define SIZE 300

int main() {
	char txt[SIZE];
	int i = 0;
	int remainder = 0;
	int num = 0;

	//scanf_s("%s", txt, sizeof(txt));
	scanf("%s", txt);
	
	while (txt[i] != '\0') {
		remainder = i % 3;
		if (remainder == 0) {
			if (!(txt[i] == 'P')){
				num++;
			}
		}
		else if (remainder == 1) {
			if (!(txt[i] == 'E')) {
				num++;
			}
		}
		else if (remainder == 2) {
			if (!(txt[i] == 'R')) {
				num++;
			}
		}
		i++;
	}

	printf("%d", num);
}