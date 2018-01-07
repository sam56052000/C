//
// Create a factory class, and use this class to create concrete factory.
//
#include "stdio.h"
#include "stdlib.h"

typedef struct product *class_product;

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

typedef struct factory
{
	class_product (*CreatFunc1)(void);

	class_product (*CreatFunc2)(void);

} class_factory;

class_factory *factory_Init(void)
{
	static class_factory *instance = NULL;

	if(instance == NULL)
	{
		instance = malloc(sizeof(class_factory));

		instance -> CreatFunc1 = Creat_product1;

		instance -> CreatFunc2 = Creat_product2;
	}

	return instance;
}

void main(void)
{
	class_factory *factory = factory_Init();

	product1_t *A;
	product2_t *B;

	A = (product1_t *)factory -> CreatFunc1();
	B = (product2_t *)factory -> CreatFunc2();

	printf("%d, %d\n", A -> para1, B -> para2);
}