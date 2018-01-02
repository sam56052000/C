//htoi function
#include <stdio.h>

int hex_to_int(char);

main()
{
	char input, hex[5];
	int i = 0;

	while((input = getchar()) != EOF)
	{
		hex[i] = input;
		i++;

		if(input == '\n')
		{
			if(hex[0] == '0' && hex[1] == 'x')
			{
				int bit1, bit0;

				bit1 = hex_to_int(hex[2]);
				bit0 = hex_to_int(hex[3]);

				printf("0x%x\n", bit1<<4 | bit0);
			}
			i = 0;
		}
	}
}

int hex_to_int(char c)
{
	int num;

	if(c >= 'A' && c <= 'F')
		num = c - 'A' + 10;
	else if(c >= 'a' && c <= 'f')
		num = c - 'a' + 10;
	else if(c >= '0' && c <= '9')
		num = c - '0';
	else
		num = 0;

	return num;
}