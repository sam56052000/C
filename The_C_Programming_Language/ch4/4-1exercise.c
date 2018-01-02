//return the position of the rightmost occurence of t in s 
#include "stdio.h"

int strindex(char s[], char t[]);

main()
{
	char s[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g','\0'};
	char t[] = {'e', 'f', 'g','\0'};

	printf("%d\n", strindex(s, t));
}

int strindex(char s[], char t[])
{
	int i, j;
	int feedback = -1;

	int loop_size = strlen(s) - strlen(t);

	for(i = 0; i <= loop_size; i++)
	{
		for(j = 0; j < strlen(t); j++)
		{
			if(s[i + j] != t[j])
				break;

			if(j == strlen(t) - 1)
				feedback = i + j;
		}
	}

	return feedback;
}