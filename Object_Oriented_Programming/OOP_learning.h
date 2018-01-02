#ifndef OOP_LEARNING_H
#define OOP_LEARNING_H

#include "stdio.h"

/*********************************************************************
 *
 *	Test 1 : Using struct
 *
 *********************************************************************/

//Encapsulation
typedef struct Object_t Object_t;
typedef int (*func_t)(Object_t *);

void Init_struct(Object_t *);

int method_1(Object_t *);
int method_2(Object_t *);

struct Object_t
{
	int a;
	int b;

	func_t method_1;
	func_t method_2;
};

#define Init_Object(a) Object_t a;Init_struct(&a)
#define ADD(obj) obj.method_1(&obj)
#define SUB(obj) obj.method_2(&obj)

//Inheritance
#define Inheritance(Father_type) Father_type Father_type##Father
#define Inhr(Father_type) Father_type##Father

typedef struct Child_t Child_t;
typedef int (*func2_t)(Child_t *);

struct Child_t
{
	func2_t method_3;

	Inheritance(Object_t);
};

//Polymorphism
int method_3_1(Child_t *child);
int method_3_2(Child_t *child);
void Init_child(Child_t *child, func2_t method3);

#define Init_Child(a,method_3) Child_t a;Init_child(&a,method_3)
#define USE_METHOD3(child) child.method_3(&child)


/*********************************************************************
 *
 *	Test 2 : Using Macro
 *
 *********************************************************************/

 #define DECLARE_STRUCT_A(name)	\
  int name##_a; 				        \
  int name##_b; 				        \
  int name##_func1(void); 		  \
  int name##_func2(void);

 #define DECLARE_FUNC1(name) 	  \
  int name##_func1(void)		    \
  { 							              \
  	return name##_a+name##_b; 	\
  }

 #define DECLARE_FUNC2(name) 	  \
  int name##_func2(void)		    \
  { 							              \
  	return name##_a-name##_b; 	\
  }

#define INIT_STRUCT_A(name)		  \
  DECLARE_STRUCT_A(name);		    \
  DECLARE_FUNC1(name);			    \
  DECLARE_FUNC2(name);

#define DECLARE_STRUCT_B_INHER_A(name)  \
  int name##_func3(void);				        \
  DECLARE_STRUCT_A(name##_A);

#define DECLARE_FUNC3_1(name) 			    \
 int name##_func3(void)					        \
 { 										                  \
 	return name##_A_a*name##_A_b; 		    \
 }

#define DECLARE_FUNC3_2(name) 			    \
 int name##_func3(void)					        \
 { 										                  \
 	return name##_A_a/name##_A_b; 		    \
 }

#define INIT_STRUCT_B_INHER_A(name,func3)	\
 DECLARE_STRUCT_B_INHER_A(name);			    \
 DECLARE_##func3(name);

#endif