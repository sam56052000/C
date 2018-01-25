#include "stdio.h"
#include "stdlib.h"

#define MAN1_POWER	100
#define MAN2_POWER	10
#define MAN3_POWER	1

typedef struct Request_t Request_t;
typedef struct Manager_t Manager_t;

struct Request_t
{
	int a;
};

struct Manager_t
{
	Manager_t *Super;

	int power;

	void (*Process)(Manager_t *, Request_t *);
};

void Process(Manager_t * man, Request_t *req)
{
	if(req -> a > man -> power)
	{
		man -> Super -> Process(man -> Super, req);
	}
	else
	{
		printf("Process by power = %d\n", man -> power);
	}
}

Manager_t *CreateMan(Manager_t *Super, int power)
{
	Manager_t *instance;

	instance = malloc(sizeof(Manager_t));

	instance -> Super = Super;

	instance -> power = power;

	instance -> Process = Process;

	return instance;
}

Request_t *CreateRequest(int para)
{
	Request_t *instance;

	instance = malloc(sizeof(Request_t));

	instance -> a = para;

	return instance;
}

void main(void)
{
	Manager_t *man1, *man2, *man3;

	man1 = CreateMan(NULL, MAN1_POWER);
	man2 = CreateMan(man1, MAN2_POWER);
	man3 = CreateMan(man2, MAN3_POWER);

	man3 -> Process(man3, CreateRequest(0));
}