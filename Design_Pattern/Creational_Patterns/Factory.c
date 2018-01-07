//
// Create each Product by each factory.
//
#include "stdio.h"
#include "stdlib.h"

typedef struct class_product *class_product;

typedef struct product1_t
{
	int para1;

	int para2;

} product1_t;

class_product Creat_product1(void)
{
	class_product instance = NULL;

	instance = malloc(sizeof(product1_t));

	((product1_t *)instance) -> para1 = 1;

	return instance;
}

typedef struct product2_t
{
	int para1;

	int para2;

} product2_t;

class_product Creat_product2(void)
{
	class_product instance = NULL;

	instance = malloc(sizeof(product2_t));

	((product2_t *)instance) -> para2 = 2;

	return instance;
}

void main(void)
{
	product1_t *A;
	product2_t *B;

	A = (product1_t *)Creat_product1();
	B = (product2_t *)Creat_product2();

	A -> para1 = 1;
	B -> para2 = 2;

	printf("%d, %d\n", A -> para1, B -> para2);
}