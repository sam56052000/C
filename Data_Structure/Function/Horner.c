#include "stdio.h"

float horner_calculate(int index, float a[],float x);

main(void)
{
	float x = 1.1f;
	float a[5] = {1, 2, 3, 4, 5};
	float sum = 0;

	sum = horner_calculate(0, a, x);

	printf("%.3f\n", sum);
}

float horner_calculate(int index, float a[], float x)
{
	float sum = 0;

	if(index < 5)
	{
		sum = a[index] + x * horner_calculate(index + 1, a, x);
	}

	return sum;
}