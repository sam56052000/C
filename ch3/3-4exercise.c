//itoa max negtive number
#include <stdio.h>
#include "ch3_func.h"

void itoa_2(int num, char out[]);

main()
{
	int num = -2147483648;

	char out[15];

	itoa_2(num, out);

	printf("%s\n", out);
}

void itoa_2(int num, char out[])
{
	int i = 0, sign;

	(num > 0) ? (sign = 1) : (sign = -1);

	while(abs(num) != 0)
	{
		out[i++] = abs(num%10) + '0';
		num *= 0.1;
	}

	if(sign == -1)
	{
		out[i++] = '-';
	}

	out[i] = '\0';

	reverse(out);
}