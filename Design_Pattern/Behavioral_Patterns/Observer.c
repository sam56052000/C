#include "stdio.h"
#include "stdlib.h"

typedef struct error_t
{
	int handle_function_num;

	void (*attach_list[3])(void);

} error_t;

void error_handling(error_t *error)
{
	int i;

	for(i = 0; i < error -> handle_function_num; i++)
	{
		error -> attach_list[i]();
	}
}

void error_handle_0(void)
{
	printf("handle number 0\n");
}

void error_handle_1(void)
{
	printf("handle number 1\n");
}

void error_handle_2(void)
{
	printf("handle number 2\n");
}

error_t *Init_error(void)
{
	static error_t error;

	error.handle_function_num = 3;

	error.attach_list[0] = error_handle_0;

	error.attach_list[1] = error_handle_1;

	error.attach_list[2] = error_handle_2;

	return &error;
}

void main(void)
{
	error_t *error = Init_error();

	error_handling(error);
}