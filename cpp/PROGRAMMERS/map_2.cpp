/* isalnum example */
#include <stdio.h>
#include <ctype.h>
int main()
{
	int i;
	char str[] = "345...";
	i = 0;
	while (isalnum(str[i])) i++;
	printf("The first %d characters are alphanumeric.\n", i);
	return 0;
}

