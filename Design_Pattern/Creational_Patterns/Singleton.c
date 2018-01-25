#include "stdio.h"
#include "stdlib.h"

typedef struct attitude_t
{
	float raw;
	float pitch;
	float yaw;

} attitude_t;

attitude_t *CreateAttitude(void)
{
	static attitude_t *instance = NULL;

	if(instance == NULL)
	{
		instance = malloc(sizeof(attitude_t));
	}

	return instance;
}

void main(void)
{
	attitude_t *A, *B;

	A = CreateAttitude();
	B = CreateAttitude();

	printf("add1 = %p, add2 = %p\n", A, B);
}