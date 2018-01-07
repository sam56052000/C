//
// Use one create function to handle all object creation.
//
#include "stdio.h"
#include "stdlib.h"

typedef struct class_product *class_product;

typedef struct product1_t
{
	int para1;

	int para2;

} product1_t;

typedef struct product2_t
{
	int para1;

	int para2;

} product2_t;

class_product CreateFunc(char input)
{
	class_product instance = NULL;

	switch(input)
	{
		case '1':
		{
			instance = malloc(sizeof(product1_t));

			((product1_t *)instance) -> para1 = 1;
		}
		break;

		case '2':
		{
			instance = malloc(sizeof(product2_t));

			((product2_t *)instance) -> para2 = 2;
		}
		break;
	}

	return instance;
}

void main(void)
{
	product1_t *A;
	product2_t *B;

	A = (product1_t *)CreateFunc('1');
	B = (product2_t *)CreateFunc('2');

	printf("%d, %d\n", A -> para1, B -> para2);
}