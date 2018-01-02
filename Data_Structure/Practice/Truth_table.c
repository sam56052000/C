#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "time.h"

#define TRUTH 1
#define FALSE 0
#define FIRST_INDEX 0

void Truth_Table(int *ptr, int num, int index);

main()
{
	double start, stop;

	start = clock();

	int n, total;

	printf("Input Number n = ");
   	scanf("%d", &n);

   	total = (int)(pow(2,n));

	printf("Have %d combination\n", total);

	int *ptr = (int *)(malloc(total));

	Truth_Table(ptr, n, FIRST_INDEX);

	free(ptr);

	stop = clock();

	printf("%f, %f\n", start, stop);
}

void Truth_Table(int *ptr, int num, int index)
{
	if(index++ < num)
	{
		*ptr = TRUTH;

		Truth_Table(ptr+1, num, index);

		*ptr = FALSE;

		Truth_Table(ptr+1, num, index);
	}
	else
	{
		int i;

		for(i = 0; i < num; i++)
		{
			if(*(ptr - num + i) == TRUTH)
			{
				printf("TRUTH ");
			}
			else
			{
				printf("FALSE ");
			}
		}
		printf("\n");
	}
}