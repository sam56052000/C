#include "stdio.h"
#include "stdlib.h"

void method1(void)
{
	printf("use method1\n");
}

void method2(void)
{
	printf("use method2\n");
}

void method3(void)
{
	printf("use method3\n");
}

void (*method)(void);

void main(void)
{
	method = method1;

	method();

	method = method2;

	method();

	method = method3;

	method();
}