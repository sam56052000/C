#include "ch6_func.h"

char getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(char c)
{
	if(bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		if(c != '\n')
			buf[bufp++] = c;
}