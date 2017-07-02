//print number with blank
#include <stdio.h>
#include "ch3_func.h"

void itoa_2(int num, char out[], int width);

main()
{
	int num = 12345;

	char out[15];

	itoa_2(num, out, 10);

	printf("%s\n", out);
}

void itoa_2(int num, char out[], int width)
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

	if(strlen(out) >= width)
		return;

	int offset_num = width - strlen(out);
	int orginal_num = strlen(out);

	for(i = 0; i <= orginal_num; i++)
	{
		out[width - i] = out[orginal_num - i];
		out[orginal_num - i] = ' ';
	}
}