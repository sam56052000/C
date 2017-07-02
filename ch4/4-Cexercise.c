#include "stdio.h"

void itoa_rec(int);

main()
{
	int test = 12345;

	itoa_rec(test);
	printf("\n");

}

void itoa_rec(int num)
{
	int rec_num = num * 0.1;

	if(rec_num > 0)
	{
		itoa_rec(rec_num);
		printf("%c", (num%10) + '0');
	}
	else
	{
		printf("%c", (num%10) + '0');
	}
}