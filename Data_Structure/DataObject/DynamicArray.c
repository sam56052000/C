#include "stdio.h"
#include "stdlib.h"

#define MAXSIZE 21
#define CENTER	10

int i;

main()
{
	//Exercise 1 : Single Array
	int Ary[MAXSIZE];
	int *pAry = &Ary[CENTER];

	for(i = 0; i < MAXSIZE; i++)
	{
		Ary[i] = i;
	}
	printf("Single Array: %d\n", pAry[10]);

	//Exercise 2 : Multi Array
	int DAry[MAXSIZE][MAXSIZE];
	int *pDAry[MAXSIZE];

	for(i = 0; i < MAXSIZE; i++)
	{
		pDAry[i] = &DAry[i][CENTER];
	}

	int **ppDAry = &pDAry[CENTER];

	ppDAry[-10][-10] = 121;
	printf("Multi Array: %d\n", DAry[0][0]);
}