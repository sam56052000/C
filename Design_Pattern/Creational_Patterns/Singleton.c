//
// One class only creat one object.
//
#include "stdio.h"
#include "stdlib.h"

typedef struct product_t
{
	int para1;

	int para2;

} product_t;

product_t * CreateFunc(void)
{
	static product_t *instance = NULL;

	if(instance == NULL)
	{
		instance = malloc(sizeof(product_t));
	}

	return instance;
}

void main(void)
{
	product_t *A, *B;

	A = CreateFunc();
	B = CreateFunc();

	printf("add1 = %p, add2 = %p\n", A, B);
}