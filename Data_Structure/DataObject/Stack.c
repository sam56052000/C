#include "stdio.h"
#include "stdlib.h"

#define USE_STATIC_STACK	1
#define USE_DYNAMIC_STACK 	0

#define MAXSIZE	100
#define SUCCESS	0
#define FAILED	1

typedef struct
{
	int *addr;
	int top;

	#if USE_DYNAMIC_STACK
	 int size;
	#endif

} Stack_t;

void StackCreat(Stack_t *stack)
{	
	#if USE_DYNAMIC_STACK
	 stack -> size = 1;
	 stack -> addr = (int *)(malloc(stack -> size * sizeof(int)));
	#else
	 stack -> addr = (int *)(malloc(MAXSIZE * sizeof(int)));
	#endif

	stack -> top = -1;
}

int IsStackFull(Stack_t *stack)
{
	#if USE_STATIC_STACK
	 if(stack -> top == MAXSIZE - 1)
	 {
		printf("Stack is Full\n");

		return FAILED;
	 }
	#else
	 if(stack -> top == stack -> size - 1)
	 {
		stack -> size *= 2;

		stack -> addr = (int *)(realloc(stack -> addr ,stack -> size * sizeof(int)));
	 }
	#endif
	
	return SUCCESS;
}

void StackPush(Stack_t *stack, int input)
{
	if(!IsStackFull(stack))
		stack -> addr [ ++stack -> top ] = input;
}

int IsStackEmpty(Stack_t *stack)
{
	if(stack -> top < 0)
	{
		printf("Stack is Empty\n");

		return FAILED;
	}

	return SUCCESS;
}

int StackPop(Stack_t *stack)
{
	if(!IsStackEmpty(stack))
		return stack -> addr [ stack -> top-- ];
}

main()
{
	Stack_t stack;
	StackCreat(&stack);
	StackPush(&stack, 1);
	StackPush(&stack, 2);
	StackPush(&stack, 3);

	printf("%d\n", StackPop(&stack));
	printf("%d\n", StackPop(&stack));
	printf("%d\n", StackPop(&stack));
	StackPop(&stack);
}

