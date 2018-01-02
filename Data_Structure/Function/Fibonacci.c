#include "stdio.h"

int Fibonacci(int index, int f1, int f2);

main()
{
	int result = Fibonacci(13, 0, 1);

	printf("%d\n", result);
}

int Fibonacci(int index, int f1, int f2)
{
	if(index > 0)
	{
		return Fibonacci(index - 1, f1 + f2, f1);
	}
	else
	{
		return f1;
	}
}