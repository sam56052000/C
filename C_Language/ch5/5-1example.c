#include <stdio.h>
#include "ch5_func.h"

main()
{
	char *pointer;

	pointer = alloc(1);

	printf("%X\n", (unsigned int)(pointer));
	printf("%X\n", (unsigned int)(allocp));

	afree(pointer);

	printf("%X\n", (unsigned int)(allocp));
}