//
// Use interface to add decorator.
//
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct people
{
	char *name;

	char decorator[300];

} people_t;

void SayHerName(people_t *people)
{
	printf("You Stand before %s %s\n", people -> name, people -> decorator);
}

void Add_1(people_t *people)
{
	static char add_name[] = "Stormborn of the House Targarven.the First of Her Name.\0";

	strcat(people -> decorator, add_name);
}

void Add_2(people_t *people)
{
	static char add_name[] = "the Unburnt\0";

	strcat(people -> decorator, add_name);
}

void Add_3(people_t *people)
{
	static char add_name[] = ", Queen of Meereen\0";

	strcat(people -> decorator, add_name);
}

void Add_4(people_t *people)
{
	static char add_name[] = ", Queen of the Andals and the Rhoynar and the First Men\0";

	strcat(people -> decorator, add_name);
}

void Add_5(people_t *people)
{
	static char add_name[] = ", Lord of the Seven Kingdoms\0";

	strcat(people -> decorator, add_name);
}

void Add_6(people_t *people)
{
	static char add_name[] = ", Protector of the Realm\0";

	strcat(people -> decorator, add_name);
}

void Add_7(people_t *people)
{
	static char add_name[] = ", Khaleesi of the Great Grass Sea\0";

	strcat(people -> decorator, add_name);
}

void Add_8(people_t *people)
{
	static char add_name[] = ", Breaker of Shackles\0";

	strcat(people -> decorator, add_name);
}

void Add_9(people_t *people)
{
	static char add_name[] = ", Mother of Dragons\0";

	strcat(people -> decorator, add_name);
}

people_t *Init_people(char *name)
{
	people_t *people = NULL;

	people = malloc(sizeof(people_t));

	people -> name = name;

	people -> decorator[0] = '\0';
}

void main(void)
{
	people_t *Daenerys;

	Daenerys = Init_people("Daenerys");

	Add_1(Daenerys);
	Add_2(Daenerys);
	Add_3(Daenerys);
	Add_4(Daenerys);
	Add_5(Daenerys);
	Add_6(Daenerys);
	Add_7(Daenerys);
	Add_8(Daenerys);
	Add_9(Daenerys);

	SayHerName(Daenerys);
}

