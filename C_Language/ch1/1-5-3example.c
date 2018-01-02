//line counting
#include <stdio.h>

main()
{
	int c, nl;

	nl = 0;

	while((c = getchar()) != EOF)
	{
		if(c == 'a')
		{
			nl++;
			printf("%d\n", nl);
		}		
	}
}