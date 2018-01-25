#include "stdio.h"
#include "stdlib.h"

typedef struct position_t position_t;
typedef struct Guidance_t Guidance_t;

struct position_t
{
	float lat;
	float lon;
	float alt;

	int (*IsHasNext)(position_t **);

	position_t *Next;
};

int IsHasNext(position_t **obj)
{
	if( (*obj) -> Next != NULL)
	{
		*obj = (*obj) -> Next;
		
		return 1;
	}
	else
	{
		return 0;
	}
}

position_t *CreatePosition(float lat, float lon, float alt, position_t *before)
{
	position_t *inctance;

	inctance = malloc(sizeof(position_t));

	inctance -> lat = lat;

	inctance -> lon = lon;

	inctance -> alt = alt;

	inctance -> IsHasNext = IsHasNext;

	inctance -> Next = NULL;

	if(before != NULL)
		before -> Next = inctance;

	return inctance;
}

struct Guidance_t
{
	void (*PathPlan)(Guidance_t *);
	void (*AddPlan)(Guidance_t *, position_t *);

	position_t *queue[5];

};

void AddPlan(Guidance_t *guidance, position_t *position)
{
	static now_index = 0;

	guidance -> queue[now_index] = position;

	if(now_index < 5)
	{
		now_index++;
	}
}

void PathPlan(Guidance_t *guidance)
{
	int i;

	for(i = 0; i < 5; i++)
	{
		printf("%.3f\n", guidance -> queue[i] -> lat);
	}
}

void main(void)
{
	Guidance_t guidnace;
	position_t *A, *B, *C, *D, *E, **obj;

	guidnace.PathPlan = PathPlan;
	guidnace.AddPlan = AddPlan;

	guidnace.AddPlan(&guidnace, A = CreatePosition(1.0f, 1.0f, 1.0f, NULL));
	guidnace.AddPlan(&guidnace, B = CreatePosition(2.0f, 1.0f, 1.0f, A));
	guidnace.AddPlan(&guidnace, C = CreatePosition(3.0f, 1.0f, 1.0f, B));
	guidnace.AddPlan(&guidnace, D = CreatePosition(4.0f, 1.0f, 1.0f, C));
	guidnace.AddPlan(&guidnace, E = CreatePosition(5.0f, 1.0f, 1.0f, D));

	obj = &A;

	//
	// Use own object to run interate.
	//
	do
	{
		printf("%.3f\n", (*obj) -> lat);

	}
	while(IsHasNext(obj));

	//
	// Use Interator
	//
	//guidnace.PathPlan(&guidnace);
}