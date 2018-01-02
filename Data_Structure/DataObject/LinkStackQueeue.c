#include "stdio.h"
#include "stdlib.h"

typedef struct stack  *StackPointer;
typedef struct queeue *QueeuePointer;

struct stack
{
	char data;

	StackPointer link;
};

struct queeue
{
	char data;

	QueeuePointer link;
};

StackPointer Top = NULL;
QueeuePointer Front = NULL, Rear = NULL;

void Push(int value)
{
	StackPointer NewStack;

	NewStack = malloc(sizeof(StackPointer));

	NewStack -> data = value;

	if(Top != NULL)
		NewStack -> link = Top;
	else
		NewStack -> link = NULL;

	Top = NewStack;
}

int Pop(void)
{
	StackPointer PopStack;

	int retData;

	if(Top == NULL)
	{
		printf("Stack Empty\n");
	}
	else
	{
		PopStack = Top;

		retData = PopStack -> data;

		Top = PopStack -> link;

		free(PopStack);
	}

	return retData;
}

void AddQ(int value)
{
	QueeuePointer NewQueeue;

	NewQueeue = malloc(sizeof(QueeuePointer));

	NewQueeue -> data = value;

	NewQueeue -> link = NULL;

	if(Front != NULL)
	{
		Rear -> link = NewQueeue;
	}
	else
	{
		Front = NewQueeue;
	}

	Rear = NewQueeue;
}

int DelQ(void)
{
	QueeuePointer PopQueeue = Front;

	int retData;

	if(Front == NULL)
	{
		printf("Queeue Empty\n");
	}
	else
	{
		retData = PopQueeue -> data;

		Front = PopQueeue -> link;

		free(PopQueeue);
	}

	return retData;
}

main()
{
	AddQ(1);
	AddQ(2);
	AddQ(3);

	printf("%d\n", DelQ());
	printf("%d\n", DelQ());
	printf("%d\n", DelQ());
	printf("%d\n", DelQ());
}