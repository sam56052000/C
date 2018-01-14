//
// Tree Data
//
#include "stdio.h"
#include "stdlib.h"

typedef struct node_t *p_node;

struct node_t
{
	p_node left;
	p_node right;
};

typedef struct class_node
{
	p_node (*Create)(void);
	void (*Add)(p_node *);
	void (*Del)(p_node *);

} class_node;

p_node Create_Node(void)
{
	return malloc(sizeof(struct node_t));
}

void Add_Node(p_node *root)
{
	*root = malloc(sizeof(struct node_t));
}

void Del_Node(p_node *root)
{
	free(*root);
}

void main(void)
{
	struct class_node node_app;

	node_app.Create = Create_Node;
	node_app.Add = Add_Node;
	node_app.Del = Del_Node;

	p_node master;

	master = node_app.Create();

	node_app.Add(&(master -> right));
}