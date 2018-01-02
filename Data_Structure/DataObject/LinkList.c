#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct listNode *listPointer;

struct listNode
{
	char data[4];
	listPointer link;
};

void CreatNode(listPointer *linklist, char *data)
{
	listPointer NewNode;

	NewNode = malloc(sizeof(listPointer));

	if(NewNode == 0)
	{
		printf("Memory Invalid\n");
	}

	*linklist = NewNode;

	(*NewNode).link = NULL;

	strcpy((*NewNode).data, data);
}

listPointer CheckLastNode(listPointer linklist)
{
	listPointer pointer;

	if((*linklist).link != NULL)
	{
		pointer = CheckLastNode((*linklist).link);
	}
	else
	{
		pointer = linklist;
	}

	return pointer;
}

void AddNewNode(listPointer *linklist, char *data)
{
	listPointer LastNode, NewNode;

	LastNode = CheckLastNode(*linklist);

	NewNode = malloc(sizeof(listPointer));

	if(NewNode == 0)
	{
		printf("Memory Invalid\n");
	}

	(*LastNode).link = NewNode;

	(*NewNode).link = NULL;

	strcpy((*NewNode).data, data);
}

listPointer Addposition(listPointer linklist, char *data)
{
	listPointer pointer;

	if((*linklist).data[0] < data[0])
	{
		pointer = Addposition((*linklist).link, data);

		if(pointer == 0)
			pointer = linklist;
	}
	else
	{
		pointer = 0;
	}

	return pointer;
}

void InsertNode(listPointer *linklist, char *data)
{
	listPointer InsertNode, NewNode;

	InsertNode = Addposition(*linklist, data);

	NewNode = malloc(sizeof(listPointer));

	if(NewNode == 0)
	{
		printf("Memory Invalid\n");
	}

	(*NewNode).link = (*InsertNode).link;

	(*InsertNode).link = NewNode;

	strcpy((*NewNode).data, data);
}

listPointer DelPreposition(listPointer linklist, char *data)
{
	listPointer pointer;

	if((*linklist).data[0] != data[0])
	{
		pointer = DelPreposition((*linklist).link, data);

		if(pointer == 0)
			pointer = linklist;
	}
	else
	{
		pointer = 0;
	}

	return pointer;
}

void DeleteNode(listPointer *linklist, char *data)
{
	listPointer PreNode, DeleteNode;

	if((*(*linklist)).data[0] == data[0])
	{
		DeleteNode = *linklist;

		*linklist = (*(*linklist)).link;

		free(DeleteNode);
	}
	else
	{
		PreNode = DelPreposition(*linklist, data);

		DeleteNode = (*PreNode).link;

		(*PreNode).link = (*(*PreNode).link).link;

		free(DeleteNode);
	}
}

void printAllNode(listPointer linklist)
{
	printf("%s\n", (*linklist).data);

	if((*linklist).link != NULL)
	{
		printAllNode((*linklist).link);
	}
}

main()
{
	listPointer link1;

	CreatNode(&link1, "bat");

	AddNewNode(&link1, "cat");
	AddNewNode(&link1, "eat");
	AddNewNode(&link1, "fat");
	AddNewNode(&link1, "gat");

	InsertNode(&link1, "dat");

	DeleteNode(&link1, "bat");
	DeleteNode(&link1, "eat");

	printAllNode(link1);
}