#include "ch5_func.h"

char *alloc(int n)
{
	if(allocbuf + ALLOCSIZE - allocp >= n)
	{
		allocp += n;

		return allocp - n;
	}
	else
	{
		return 0;
	}
}

void afree(char *p)
{
	if(p >= allocbuf && p < allocbuf + ALLOCSIZE)
		allocp = p;
}

int readlines(char *lineptr[], int maxlines)
{
	int len, nlines;
	char *p, line[MAXLINE];

	nlines = 0;

	while((len = get_line(line, MAXLINE)) > 0)
	{
		if((nlines >= maxlines) || (p = alloc(len)) == NULL)
		{	
			return -1;
		}
		else
		{
			line[len - 1] = '\0';

			strcpy(p, line);

			lineptr[nlines++] = p;
		}

		return nlines;
	}
}

void writelines(char *lineptr[], int nlines)
{
	int i;

	for(i = 0; i < nlines; i++)
	{
		printf("%s\n", lineptr[i]);
	}
}