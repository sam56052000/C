#include "stdio.h"
#include "string.h"
#include "stdlib.h"

#define MAXSIZE 100

void strings(char *s, char *t, int i);

char s[] = "amobile";
char t[] = "uto";

main()
{
	char temp[MAXSIZE];

	strncpy(temp, s, 1);

	printf("%s\n", temp);

	strcat(temp, t);

	printf("%s\n", temp);

	strcat(temp, s+1);

	printf("%s\n", temp);
}

void strings(char *s, char *t, int i)
{
	char string[MAXSIZE], *temp = string;

	// if(i < 0 && i > strlen(s))
	// {
	// 	fprintf(stderr, "position is out of bounds\n");
	// 	exit(EXIT_FAILUE);
	// }

	if(!strlen(s)) strcpy(s, t);
	else if (strlen(t))
	{
		strncpy(temp, s, i);
		strcat(temp, t);
		strcat(temp, (s + i));
		strcpy(s, temp);
	}
}