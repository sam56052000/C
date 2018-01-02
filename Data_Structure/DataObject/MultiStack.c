#include "stdio.h"
#include "stdlib.h"

#define MAXSIZE			20
#define STACK_NUMBER	5
#define SUCCESS			0
#define FAILED			1

#define EMPTY_LOW_LIMIT	3

typedef struct
{
	int *addr;
	int top[STACK_NUMBER + 1];
	int bound[STACK_NUMBER + 1];

} Stack_t;

int StackEmptySpace_Number(Stack_t *stack);
int AssignStackIndex(Stack_t *stack, int stack_index);
void AssignStackMemory(Stack_t *stack, int stack_index, int assign_index);

void StackCreat(Stack_t *stack)
{	
	stack -> addr = (int *)(malloc(MAXSIZE * sizeof(int)));

	stack -> top[0]		= -1;
	stack -> bound[0]	= -1;

	int j;

	for(j = 1; j < STACK_NUMBER; j++)
	{
		stack -> top[j]		= (MAXSIZE / STACK_NUMBER) * j - 1;
		stack -> bound[j]	= (MAXSIZE / STACK_NUMBER) * j - 1;
	}

	stack -> bound[STACK_NUMBER] = MAXSIZE - 1;
}

int IsStackFull(Stack_t *stack, int stack_index)
{
	if(stack -> top[stack_index] == stack -> bound[stack_index + 1])
	{
		if(StackEmptySpace_Number(stack) < EMPTY_LOW_LIMIT)
		{
			printf("Stack is Full\n");

			return FAILED;
		}
		else
		{
			int Assign_index;

			Assign_index = AssignStackIndex(stack, stack_index);

			printf("Assign Stack[%d]\n", Assign_index);

			AssignStackMemory(stack, stack_index, Assign_index);
		}
	}

	return SUCCESS;
}

void StackPush(Stack_t *stack, int stack_index, int input)
{
	if(!IsStackFull(stack, stack_index))
		stack -> addr [ ++(stack -> top[stack_index]) ] = input;
}

int IsStackEmpty(Stack_t *stack, int stack_index)
{
	if(stack -> top[stack_index] <= stack -> bound[stack_index])
	{
		printf("Stack is Empty\n");

		return FAILED;
	}

	return SUCCESS;
}

int StackPop(Stack_t *stack, int stack_index)
{
	if(!IsStackEmpty(stack, stack_index))
		return stack -> addr [ (stack -> top[stack_index])-- ];
}

void print_stack(Stack_t *stack)
{
	printf("t0=%d,b0=%d,t1=%d,b1=%d,t2=%d,b2=%d,t3=%d,b3=%d,t4=%d,b4=%d\n",
	stack->top[0], stack->bound[0], stack->top[1], stack->bound[1],
	stack->top[2], stack->bound[2], stack->top[3], stack->bound[3],
	stack->top[4], stack->bound[4]);
}

main()
{
	int input = 0;

	Stack_t stack;
	StackCreat(&stack);

	StackPush(&stack, 2, input++);
	print_stack(&stack);

	StackPush(&stack, 2, input++);
	print_stack(&stack);

	StackPush(&stack, 2, input++);
	print_stack(&stack);

	StackPush(&stack, 2, input++);
	print_stack(&stack);

	StackPush(&stack, 2, input++);
	print_stack(&stack);

	StackPush(&stack, 2, input++);
	print_stack(&stack);

	StackPush(&stack, 3, input++);
	print_stack(&stack);

	StackPush(&stack, 3, input++);
	print_stack(&stack);

	StackPush(&stack, 3, input++);
	print_stack(&stack);

	StackPush(&stack, 3, input++);
	print_stack(&stack);

	StackPush(&stack, 3, input++);
	print_stack(&stack);

	StackPush(&stack, 3, input++);
	print_stack(&stack);

	StackPush(&stack, 2, input++);
	print_stack(&stack);

	StackPush(&stack, 2, input++);
	print_stack(&stack);

	StackPush(&stack, 2, input++);
	print_stack(&stack);

	StackPush(&stack, 2, input++);
	print_stack(&stack);

	StackPush(&stack, 2, input++);
	print_stack(&stack);

	StackPush(&stack, 4, input++);
	print_stack(&stack);

	int i;
	for(i = 0; i < MAXSIZE; i++)
		printf("addr[%d] = %d\n", i, stack.addr[i]);
}

int StackEmptySpace_Number(Stack_t *stack)
{
	int Sum = 0, i = STACK_NUMBER - 1;

	do
	{
		Sum += (stack -> top[i] - stack -> bound[i]);
	}
	while(i-- != 0);

	return MAXSIZE - Sum;
}

int AssignStackIndex(Stack_t *stack, int stack_index)
{
	int i = stack_index + 1;

	for( ; i < STACK_NUMBER; i++)
	{
		if(stack -> top[i] < stack -> bound[i + 1])
			return i;
	}

	i = stack_index - 1;

	for( ; i >= 0; i--)
	{
		if(stack -> top[i] < stack -> bound[i + 1])
			return i;
	}
}

void AssignStackMemory(Stack_t *stack, int stack_index, int assign_index)
{
	int i;

	if(assign_index > stack_index)
	{
		for(i = stack -> top[assign_index]; i > stack -> top[stack_index]; i--)
		{
			stack -> addr[i + 1] = stack -> addr[i];
		}
		for(i = stack_index + 1; i <= assign_index; i++)
		{
			stack -> top[i] += 1;
			stack -> bound[i] += 1;
		}
	}
	else
	{
		for(i = stack -> bound[assign_index + 1] + 1; i <= stack -> top[stack_index]; i++)
		{
			stack -> addr[i - 1] = stack -> addr[i];
		}
		for(i = assign_index + 1; i <= stack_index; i++)
		{
			stack -> top[i] -= 1;
			stack -> bound[i] -= 1;
		}
	}
}