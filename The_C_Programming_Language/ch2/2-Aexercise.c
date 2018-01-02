//Rewrite lower function
#include <stdio.h>

#define array_size 5

void lower_alt(char []);

main()
{
	char s[array_size] = {'A', 'b', 'C', 'd', 'E'};

	lower_alt(s);

	printf("%s\n", s);
}

void lower_alt(char s[])
{
	int i = 0;

	while(i < array_size)
	{
		s[i] = (s[i] >= 'A' && s[i] <= 'Z') ? (s[i] - 'A' + 'a') : (s[i]);

		i++;
	}
}