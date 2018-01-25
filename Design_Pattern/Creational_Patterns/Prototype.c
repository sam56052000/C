#include "stdio.h"
#include "stdlib.h"

typedef struct object_t
{
	int a;
	int b;
	int c;

} object_t;

object_t *CreateObject(void)
{
	object_t *instance;

	instance = malloc(sizeof(object_t));

	instance -> a = 1;
	instance -> b = 2;
	instance -> c = 3;

	return instance;
}

object_t *CloneObject(object_t *src)
{
	object_t *instance;

	instance = malloc(sizeof(object_t));

	instance -> a = src -> a;
	instance -> b = src -> b;
	instance -> c = src -> c;

	return instance;	
}

void main(void)
{
	object_t *A, *B;

	A = CreateObject();
	B = CloneObject(A);

	printf("A=%d, %d, %d\n", A -> a, A -> b, A -> c);
	printf("B=%d, %d, %d\n", B -> a, B -> b, B -> c);
}