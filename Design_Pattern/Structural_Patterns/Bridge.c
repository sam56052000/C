#include "stdio.h"
#include "stdlib.h"

#define ROTOR 		0
#define FIXED_WING 	1

typedef struct position_t position_t;
typedef struct planemode_t planemode_t;

struct position_t
{
	float lat;
	float lon;
	float alt;

	void (*fly)(position_t *);
};

struct planemode_t
{
	void (*rotor)(position_t *);
	void (*fixed_wing)(position_t *);
};

void rotor(position_t *pos)
{
	printf("fly to %.3f by rotor mode\n", pos -> lat);
}

void fixed_wing(position_t *pos)
{
	printf("fly to %.3f by fixed-wing mode\n", pos -> lat);
}

planemode_t *CreatePlaneMode(void)
{
	planemode_t *planemode;

	planemode = malloc(sizeof(planemode_t));

	planemode -> rotor = rotor;
	planemode -> fixed_wing = fixed_wing;

	return planemode;
}

position_t *CreatePosition(float lat, planemode_t *planemode, int mode)
{
	position_t *pos;

	pos = malloc(sizeof(position_t));

	pos -> lat = lat;

	if(mode == ROTOR)
	{
		pos -> fly = planemode -> rotor;
	}
	else if(mode == FIXED_WING)
	{
		pos -> fly = planemode -> fixed_wing;
	}

	return pos;
}

void main(void)
{
	planemode_t *planemode;
	position_t *A, *B;

	planemode = CreatePlaneMode();

	A = CreatePosition(1.0f, planemode, ROTOR);
	B = CreatePosition(2.0f, planemode, FIXED_WING);

	A -> fly(A);
	B -> fly(B);
}