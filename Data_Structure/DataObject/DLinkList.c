#include "stdio.h"
#include "stdlib.h"

typedef struct node *nodePointer;

struct node
 {
 	int data;

 	nodePointer llink;
 	nodePointer rlink;
 };

nodePointer CreatNode(char data)
{
	nodePointer NewNode;

	NewNode = malloc(sizeof(nodePointer));

	if(NewNode == 0)
	{
		printf("Memory Invalid\n");
	}

	(*NewNode).llink = NULL;

	(*NewNode).rlink = NULL;

	(*NewNode).data = data;

	return NewNode;
}

nodePointer CheckLastNode(nodePointer linklist)
{
	nodePointer pointer;

	if((*linklist).rlink != NULL)
	{
		pointer = CheckLastNode((*linklist).rlink);
	}
	else
	{
		pointer = linklist;
	}

	return pointer;
}

void AddNewNode(nodePointer *linklist, char data)
{
	nodePointer LastNode, NewNode;

	LastNode = CheckLastNode(*linklist);

	NewNode = malloc(sizeof(nodePointer));

	if(NewNode == 0)
	{
		printf("Memory Invalid\n");
	}

	(*NewNode).data = data;

	(*LastNode).rlink = NewNode;
	(*NewNode).llink = *linklist;
	(*NewNode).rlink = NULL;
}

nodePointer Addposition(nodePointer linklist, char data)
{
	nodePointer pointer;

	if((*linklist).data < data)
	{
		pointer = Addposition((*linklist).rlink, data);

		if(pointer == 0)
			pointer = linklist;
	}
	else
	{
		pointer = 0;
	}

	return pointer;
}

void InsertNode(nodePointer *linklist, char data)
{
	nodePointer InsertNode, NewNode, NextNode;

	InsertNode = Addposition(*linklist, data);

	NewNode = malloc(sizeof(nodePointer));

	if(NewNode == 0)
	{
		printf("Memory Invalid\n");
	}

	(*NewNode).data = data;

	NextNode = (*InsertNode).rlink;

	(*NextNode).llink = NewNode;

	(*NewNode).rlink = NextNode;

	(*NewNode).llink = InsertNode;

	(*InsertNode).rlink = NewNode;
}

nodePointer DelPosition(nodePointer linklist, char data)
{
	nodePointer pointer;

	if((*linklist).data != data)
	{
		pointer = DelPosition((*linklist).rlink, data);
	}
	else
	{
		pointer = linklist;
	}

	return pointer;
}

void DeleteNode(nodePointer *linklist, char data)
{
	nodePointer PreNode, DeleteNode, NextNode;

	if((*(*linklist)).data == data)
	{
		DeleteNode = *linklist;

		*linklist = (*(*linklist)).rlink;

		free(DeleteNode);
	}
	else
	{
		DeleteNode = DelPosition(*linklist, data);

		PreNode = (*DeleteNode).llink;

		NextNode = (*DeleteNode).rlink;

		(*PreNode).rlink = NextNode;
		(*NextNode).llink = PreNode;

		free(DeleteNode);
	}
}

void printAllNode(nodePointer linklist)
{
	printf("%c\n", (*linklist).data);

	if((*linklist).rlink != NULL)
	{
		printAllNode((*linklist).rlink);
	}
}

main()
{
	nodePointer Dlink = CreatNode('A');

	AddNewNode(&Dlink, 'C');
	AddNewNode(&Dlink, 'D');

	InsertNode(&Dlink, 'B');

	DeleteNode(&Dlink, 'C');
	AddNewNode(&Dlink, 'E');

	printAllNode(Dlink);
}