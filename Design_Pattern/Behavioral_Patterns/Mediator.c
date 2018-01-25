#include "stdio.h"
#include "stdlib.h"

typedef struct Messager_t Messager_t;
typedef struct Interface_t Interface_t;

struct Messager_t
{
	int number;

	void (*send)(Interface_t *, Messager_t*);
	void (*boardcast)(Interface_t *);
};

struct Interface_t
{
	void (*send)(Messager_t*);
	void (*boardcast)();
};

void send(Messager_t *to)
{
	printf("sned to %d\n", to -> number);
}

void boardcast(void)
{
	printf("send to all\n");
}

void messager_send(Interface_t *interface, Messager_t *to)
{
	interface -> send(to);
}

void messager_all(Interface_t *interface)
{
	interface -> boardcast();
}

Messager_t *CreateMessager(int number)
{
	Messager_t *messager;

	messager = malloc(sizeof(Messager_t));

	messager -> number = number;

	messager -> send = messager_send;

	messager -> boardcast = messager_all;
}

void main(void)
{
	Interface_t interface;

	interface.send = send;
	interface.boardcast = boardcast;

	Messager_t *plane1, *plane2, *tower;

	tower = CreateMessager(0);
	plane1 = CreateMessager(1);
	plane2 = CreateMessager(2);

	plane1 -> send(&interface, plane2);
	plane1 -> boardcast(&interface);
}