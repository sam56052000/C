#include "stdio.h"
#include "stdlib.h"

#define MAX_TERMS 100
#define COMPARE(x,y) ((x)<(y))?-1:((x)==(y))?0:1

typedef struct 
{
	float coef;
	int expon;

} polynomial;

polynomial terms[MAX_TERMS];

int avail = 5;

void attach(float cofficient, int exponent);
void padd(int startA, int finishA ,int startB, int finishB, int *startD, int *finsihD);

main()
{
	terms[0].coef = 3;
	terms[0].expon = 3;
	terms[1].coef = 1;
	terms[1].expon = 1;

	terms[2].coef = 6;
	terms[2].expon = 6;
	terms[3].coef = 4;
	terms[3].expon = 4;
	terms[4].coef = 2;
	terms[4].expon = 2;

	int startA = 0, finishA = 1, startB = 2, finishB = 4;
	int startD, finsihD;

	padd(startA, finishA, startB, finishB, &startD, &finsihD);

	int i;
	for(i = 0; i < avail; i++)
	{
		printf("term = %d, coef = %f, exp = %d\n", i, terms[i].coef, terms[i].expon);
	}	
}

void padd(int startA, int finishA ,int startB, int finishB, int *startD, int *finsihD)
{ 
	float cofficient;

	*startD = avail;

	while(startA <= finishA && startB <= finishB)
	{
		switch(COMPARE(terms[startA].expon, terms[startB].expon))
		{
			case -1:
			{
				attach(terms[startB].coef, terms[startB].expon);
				startB++;
			}
			break;

			case 0:
			{
				cofficient = terms[startA].coef + terms[startB].coef;

				if(cofficient)
				{
					attach(cofficient, terms[startA].expon);
				}
				startA++;
				startB++;
			}
			break;

			case 1:
			{
				attach(terms[startA].coef, terms[startA].expon);
				startA++;
			}
		}
	}

	for(; startA <= finishA; startA++)
		attach(terms[startA].coef, terms[startA].expon);

	for(; startB <= finishB; startB++)
		attach(terms[startB].coef, terms[startB].expon);

	*finsihD = avail - 1;
}

void attach(float cofficient, int exponent)
{
	terms[avail].coef = cofficient;
	terms[avail++].expon = exponent;
}