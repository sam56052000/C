#include "stdio.h"

#define BOTTOM 64

typedef struct Tower_t
{
	int top, bottom;

} Tower_t;

void Init_tower(Tower_t *);
void print_tower(Tower_t *, int);
void Hanoi_Alg(Tower_t *);
void hanoi_res(Tower_t *, Tower_t *, Tower_t *);
int down_tower(Tower_t *, Tower_t *, Tower_t *);
void shift_tower(Tower_t *, Tower_t *, Tower_t *);

main()
{
	Tower_t tower[3];

	Init_tower(tower);

	Hanoi_Alg(tower);
}

void Init_tower(Tower_t *tower)
{
	tower -> top = 1;
	tower -> bottom = BOTTOM;

	((Tower_t *)(tower + 1)) -> top = 0;
	((Tower_t *)(tower + 1)) -> bottom = 0;

	((Tower_t *)(tower + 2)) -> top = 0;
	((Tower_t *)(tower + 2)) -> bottom = 0;
}

void print_tower(Tower_t * tower, int step)
{
	printf("STEP : %d\n", step);
	printf("\n");
	printf("\n");
	printf("%d       %d       %d\n", tower -> top, ((Tower_t *)(tower + 1)) -> top, ((Tower_t *)(tower + 2)) -> top);
	printf("||      ||      ||\n");
	printf("%d       %d       %d\n", tower -> bottom, ((Tower_t *)(tower + 1)) -> bottom, ((Tower_t *)(tower + 2)) -> bottom);
	printf("====================\n");
	printf("\n");
	printf("\n");
	printf("\n");
}

void Hanoi_Alg(Tower_t *tower)
{
	Tower_t *t1, *t2, *t3;

	int step = 0;

	print_tower(tower, step++);

	t1 = tower;
	t2 = (Tower_t *)(tower + 1);
	t3 = (Tower_t *)(tower + 2);

	//Start Section
	down_tower(t1, t2, t3);
	print_tower(tower, step++);
	down_tower(t1, t2, t3);
	print_tower(tower, step++);
	shift_tower(t1, t2, t3);
	print_tower(tower, step++);

	while(down_tower(t1, t2, t3))
	{
		if(t1 -> top > BOTTOM)
		{
			t1 -> top = 0;

			t1 -> bottom = 0;

			break;
		}

		print_tower(tower, step++);

		shift_tower(t1, t2, t3);

		print_tower(tower, step++);
	}

	//End Section
	print_tower(tower, step++);
	shift_tower(t1, t2, t3);
	print_tower(tower, step++);
}

int down_tower(Tower_t * t1, Tower_t *t2, Tower_t *t3)
{
	if(t1 -> top % 2 == 1)
	{	
		t2 -> bottom = t1 -> top;
	}
	else
	{
		t3 -> bottom = t1 -> top;
	}

	if(t1 -> top == BOTTOM + 1)
	{
		return 0;
	}

	t1 -> top += 1;

	return 1;
}

void shift_tower(Tower_t * t1, Tower_t *t2, Tower_t *t3)
{
	if(t2 -> bottom > t3 -> bottom)
	{
		if(t3 -> top == 0)
		{
			t2 -> top = t3 -> bottom;
		}
		else
		{
			t2 -> top = t3 -> top;
		}
		
		t3 -> top = 0;

		t3 -> bottom = 0;
	}
	else
	{
		if(t2 -> top == 0)
		{
			t3 -> top = t2 -> bottom;
		}
		else
		{
			t3 -> top = t2 -> top;
		}

		t2 -> top = 0;

		t2 -> bottom = 0;
	}
}