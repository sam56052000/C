#include "stdio.h"
#include "string.h"

main()
{
	char c;

	while((c = getchar()) != EOF)
	{
		putchar(c+1);
	}
}