//convert tab and new line to visible
#include <stdio.h>

void clear_buffer(char s[]);

main()
{	
	char c, s[100];
	int i = 0;

	while((c = getchar()) != EOF)
	{
		s[i] = c;
		
		switch (c)
		{
			case '\n':
				s[i] = '/';
				s[++i] = 'n';
				break;
			case '\t':
				s[i] = '/';
				s[++i] = 't';
				i++;
				break;
			default:
				i++;
				break;
		}

		if(c == '\n')
		{	
			s[++i] = '\0';
			printf("%s\n", s);
			clear_buffer(s);
			i = 0;
		}	
	}
}

void clear_buffer(char s[])
{
	int j;

	for(j = 0; j < 100; j++)
	{
		s[j] = 0;
	}
}