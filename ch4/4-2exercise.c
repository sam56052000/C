//Extend scientific number
#include "stdio.h"
#include "stdlib.h"
#include "math.h"

float atof_2(char *s);

main()
{
	char *s = "-1.23e1";

	printf("%d\n", strlen(s));
	printf("%f\n", atof_2(s));
}

float atof_2(char *s)
{
	char i, j;
	char num_length;
	char *_exp;

	for(i = 0; i < strlen(s); i++)
	{
		if(*(s + i) == 'e')
		{
			_exp = s + i + 1;
			num_length = i;
			break;
		}
	}

	char *num = malloc(num_length);

	for(i = 0; i < num_length; i++)
	{
		*(num + i) = s[i];
	}

	float num_f = atof(num);
	int exp_f = atoi(_exp);
	float exp_dec;

	if(*_exp == '-')
		exp_dec = 0.1f;
	else
		exp_dec = 10.0f;

	for(i = 1; i <= abs(exp_f); i++)
	{
		num_f *= exp_dec;
	}

	free(num);

	return num_f;
}