//convert integer to base b number
#include "stdio.h"
#include "ch3_func.h"

#define ARRAYSIZE 100

void clear_buff(char *);
void itob(int n, char s[], int b);

main()
{
	char array[ARRAYSIZE], output[ARRAYSIZE];
	char c;
	int i = 0;

	while((c = getchar()) != EOF)
	{
		array[i++] = c;

		if(c == '\n')
		{
			array[i] = '\0';

			i = 0;

			itob(atoi(array), output, 16);

			printf("%s\n", output);

			clear_buff(array);
		}
	}
}

void clear_buff(char *buffer)
{
	int i;

	for(i = 0; i < ARRAYSIZE; i++)
	{
		buffer[i] = 0;
	}
}

void itob(int n, char s[], int b)
{	
	int dec_num = n, hex_num;
	int i = 0;

	while(dec_num > 0)
	{
		hex_num = dec_num % b;

		if(hex_num > 9)
			s[i++] = hex_num - 10 + 'A';
		else
			s[i++] = hex_num + '0';

		dec_num = dec_num / b;
	}

	s[i] = '\0';

	reverse(s);
}