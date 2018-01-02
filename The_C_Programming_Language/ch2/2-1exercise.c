//variable type range
#include <stdio.h>

main()
{
	char max_char = 0, min_char = 0;
	short max_short = 0, min_short = 0;
	long max_long = 0, min_long = 0;
	int max_int = 0, min_int = 0;
	unsigned short max_uint = 0, min_uint = 1;

	while(min_char >= 0)
	{
		min_char += 1;
	}
	max_char = min_char - 1;

	while(min_short >= 0)
	{
		min_short += 1;
	}
	max_short = min_short - 1;

	while(min_long >= 0)
	{
		min_long += 1;
	}
	max_long = min_long - 1;

	while(min_int >= 0)
	{
		min_int += 1;
	}
	max_int = min_int - 1;

	while(min_uint > 0)
	{
		min_uint += 1;
	}
	max_uint = max_uint - 1;

	printf("max char = %d, short = %d, long = %ld, int = %d, uint = %d\n",
		max_char, max_short, max_long, max_int , max_uint);

	printf("min char = %d, short = %d, long = %ld, int = %d, uint = %d\n",
		min_char, min_short, min_long, min_int , min_uint);
}