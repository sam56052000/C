#define OOP_LEARNING_C
#include "OOP_learning.h"

/*********************************************************************
 *
 *	Test 1 : Using struct
 *
 *********************************************************************/

int method_1(Object_t *Object)
{
	return Object -> a + Object -> b;
}

int method_2(Object_t *Object)
{
	return Object -> a - Object -> b;
}

int method_3_1(Child_t *child)
{
	return child -> Inhr(Object_t).a * child -> Inhr(Object_t).b;
}

int method_3_2(Child_t *child)
{
	return child -> Inhr(Object_t).a / child -> Inhr(Object_t).b;
}

void Init_struct(Object_t *Object)
{
	Object -> method_1 = method_1;
	Object -> method_2 = method_2;
}

void Init_child(Child_t *child, func2_t method3)
{
	child -> method_3 = method3;
}

/*********************************************************************
 *
 *	Test 2 : Using Macro
 *
 *********************************************************************/