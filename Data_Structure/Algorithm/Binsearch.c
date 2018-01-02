#include "stdlib.h"
#include "stdio.h"

#define ARRAY_SIZE 1000000

#define METHOD_N	1
#define METHOD_R	0
#define METHOD METHOD_N

#define COMPARE(x,y) ((x)<(y))?-1:((x)==(y))?0:1

int binsearch_normal(int list[], int searchnum, int left, int right);
int binsearch_recursion(int list[], int searchnum, int left, int right);

main()
{
	int test_array[ARRAY_SIZE];

	int i = ARRAY_SIZE - 1;

	int search = 100, result;

	time_t clock_start, clock_stop;

	do
	{
		test_array[i] = i;
	}
	while(i-- != 0);

	#if	METHOD == METHOD_N
	 printf("Use Normal Method\n");
	 result = binsearch_normal(test_array, search, 0, ARRAY_SIZE - 1);

	#elif METHOD == METHOD_R
	 printf("Use Recursion Method\n");
	 result = binsearch_recursion(test_array, search, 0, ARRAY_SIZE - 1);

	#endif

	printf("result = %d\n", result);

}

int binsearch_normal(int list[], int searchnum, int left, int right)
{
	int mid;

	while(left <= right)
	{
		mid = (left + right) * 0.5;

		switch(COMPARE(list[mid], searchnum))
		{
			case -1:
			{
				left = mid + 1;
			}
			break;

			case 0:
			{
				return mid;
			}
			break;

			case 1:
			{
				right = mid - 1;
			}
			break;
		}
	}

	return -1;
}

int binsearch_recursion(int list[], int searchnum, int left, int right)
{
	int mid;

	mid = (left + right) * 0.5;

	if(left <= right)
	{
		switch(COMPARE(list[mid], searchnum))
		{
			case -1: return binsearch_recursion(list, searchnum, mid + 1, right);

			case  0: return mid;

			case  1: return binsearch_recursion(list, searchnum, left, mid - 1);
		}
	}

	return -1;
}