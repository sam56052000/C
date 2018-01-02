#include <stdio.h>
#include "calc.h"

#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

void push(double f)
{
	if(sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n", f);
}

double pop(void)
{
	if(sp > 0)
		return val[--sp];
	else
	{
		printf("error: stack empty\n");
		return 0.0;
	}
}

double print_top(void)
{
	if(sp > 0)
		return val[sp - 1];
	else
	{
		printf("error: stack empty\n");
		return 0.0;
	}
}

void swap_top2(void)
{	
	if(sp < 2)
	{
		printf("Not enough to swap\n");
		return;
	}

	double temp;

	temp = val[sp - 1];
	val[sp - 1] = val[sp - 2];
	val[sp - 2] = temp;
}

void clear_stack(void)
{
	while(sp-- > 0)
		val[sp - 1] = 0;
}