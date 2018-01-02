#include "stdio.h"
#include "stdlib.h"

#define AND 	2
#define OR 		3
#define NOT		4
#define TRUE	1
#define FALSE	0
#define VAR 	5

typedef struct node *treePointer;

struct node
{
	int value;
	int data;

	treePointer left, right; 
};

treePointer CreatTree(int value, int data, treePointer *father)
{
	treePointer NewTree;

	NewTree = malloc(sizeof(*NewTree));

	if(father != NULL)
	{
		*father = NewTree;
	}

	NewTree -> value = value;
	NewTree -> data = data;
	NewTree -> left = NULL;
	NewTree -> right = NULL;
	
	return NewTree;
}

void inorder(treePointer ptr)
{
	if(ptr)
	{
		inorder(ptr -> left);
		printf("%d\n", ptr -> value);
		inorder(ptr -> right);
	}
}

void preorder(treePointer ptr)
{
	if(ptr)
	{
		printf("%d\n", ptr -> value);
		preorder(ptr -> left);
		preorder(ptr -> right);
	}
}

void postorder(treePointer ptr)
{
	if(ptr)
	{
		postorder(ptr -> left);
		postorder(ptr -> right);
		printf("%d\n", ptr -> value);
	}
}

treePointer TreeCopy(treePointer source)
{
	treePointer temp;

	if(source)
	{
		temp = malloc( sizeof(temp) );
		temp -> left = TreeCopy(source -> left);
		temp -> right = TreeCopy(source -> right);
		temp -> value = source -> value;

		return temp;
	}

	return NULL;
}

int TreeEqual(treePointer first, treePointer second)
{
	return	( !first && !second )
		||	( first && second 
			 && (first -> value == second -> value)
			 && TreeEqual(first -> left, second -> left)
			 && TreeEqual(first -> right, second -> right)
			);
}

void postOrderEval(treePointer node)
{
	if(node)
	{
		postOrderEval(node -> left);
		postOrderEval(node -> right);

		switch(node -> data)
		{
			case NOT :
			{
				node -> value = ~( node -> right -> value );
			}
			break;
			case AND :
			{
				node -> value = (node -> right -> value) & (node -> left -> value);
			}
			break;
			case OR :
			{
				node -> value = (node -> right -> value) | (node -> left -> value);
			}
			break;
			case TRUE :
			{
				node -> value = 1;
			}
			break;
			case FALSE:
			{
				node -> value = 0;
			}
			break;
		}
	}
}

main()
{
	treePointer master;

	master = CreatTree(0, OR, NULL);

	CreatTree(0x0, OR , &(master -> left) );
	CreatTree(0x0, NOT, &(master -> right) );

	CreatTree(0x0, AND, &(master -> left -> left) );
	CreatTree(0x0, AND, &(master -> left -> right) );
	CreatTree(0x4, VAR, &(master -> right -> right) );

	CreatTree(0x1, VAR, &(master -> left -> left -> left) );
	CreatTree(0x0, NOT, &(master -> left -> left -> right) );
	CreatTree(0x0, NOT, &(master -> left -> right -> left) );
	CreatTree(0x4, VAR, &(master -> left -> right -> right) );

	CreatTree(0x2, VAR, &(master -> left -> left -> right -> right) );
	CreatTree(0x1, VAR, &(master -> left -> right -> left -> right) );

	// copy = TreeCopy(master);

	postOrderEval(master);

	printf("%d\n", master -> value);

	// printf("%d\n", TreeEqual(master, copy));
}