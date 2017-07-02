//Character Arrays
#include <stdio.h>
#include "ch1_func.h"

#define MAXLINE 1000

main()
{
	int len, max;
	char line[MAXLINE], longest[MAXLINE];

	max = 0;

	while((len = get_line(line, MAXLINE)) > 0)
	{
		if(len > max)
		{
			max = len;
			copy(longest, line);
		}

		if(max > 0)
		{
			printf("%s", longest);
		}
	}

	return 0;
}