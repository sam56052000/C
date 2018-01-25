#include "stdio.h"
#include "stdlib.h"

typedef struct character_t character_t;
typedef struct state_t state_t;

struct state_t
{
	void (*heal)(character_t *);
	void (*recover)(character_t *);
};

struct character_t
{
	int hp;
	int mp;

	state_t *state;
};

void heal(character_t *man)
{
	man -> hp += 10;
}

void recover1(character_t *man)
{
	man -> mp += 10;
}

void recover2(character_t *man)
{
	man -> mp += 20;
}

void Check_State(character_t *man, state_t *normal, state_t *hurt)
{
	if(man -> hp > 250)
	{
		man -> state = normal;
	}
	else
	{
		man -> state = hurt;
	}
}

void main(void)
{
	// Init State
	state_t normal, hurt;

	normal.heal = heal;
	normal.recover = recover1;

	hurt.heal = heal;
	hurt.recover = recover2;

	// Init man
	character_t man;

	man.hp = 500;
	man.mp = 500;
	man.state = &normal;

	Check_State(&man, &normal, &hurt);
	man.state -> heal(&man);
	man.state -> recover(&man);
}