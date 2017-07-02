//Using loop without && and ||
#include <stdio.h>

main()
{
	char c;
	int lim = 10;
	char s[lim];
	int i = 0;

	for(i = 0; i < lim; i++)
	{
		s[i] = 0;
	}
	
	i = 0;

	while(i < lim)
		if((c = getchar()) != EOF)
			if(c != '\n')
			{
				s[i] = c;
				printf("%s\n", s);
				i++;
			}
}