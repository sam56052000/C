//binsearch (can't test time)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int binsearch(int x, int v[], int n);

main()
{	
	int i,x = 100000,n = 2000000;
	int v[n], ans;

	for(i = 0;i < n; i++)
		v[i] = i;
	
	double clock_start, clock_stop;
	clock_start = clock();

	ans = binsearch(x, v, n);

	clock_stop = clock();
	printf("ans = %d, %fus\n", ans, ((clock_stop-clock_start)));
}

int binsearch(int x, int v[], int n)
{
	int low, high, mid = 0;
	int j;

	low = 0;
	high = n - 1;

	while(low <= high)
	{
		mid = (low + high) * 0.5;

		//Test Method 1
		if(x < v[mid])
		{
			high = mid;
		}
		else if(x > v[mid])
		{
			low = mid;
		}
		else
		{
			return mid;
		}

		//Test Method 2
	}

	return -1;
}