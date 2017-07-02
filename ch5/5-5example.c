#include "stdio.h"
#include "string.h"
#include "ch5_func.h"

#define MAXLINE 5000

char *lineptr[MAXLINE];

void qsort(void *lineptr[], int left, int right, int (*comp)(void *, void *));
int numcmp(char *, char *);

main(int argc, char *argv[])
{
	int nlines;
	int numeric = 0;

	if(argc > 1 && strcmp(argv[1], "-n") == 0)
		numeric = 1;

	if((nlines = readlines(lineptr, MAXLINE)) >= 0)
	{
		qsort((void **)lineptr, 0, nlines - 1, (int (*)(void *, void *))(numeric ? numcmp : strcmp));

		writelines(lineptr, nlines);

		return;
	}
	else
	{
		printf("input too big to sort\n");
		return 1;
	}
}