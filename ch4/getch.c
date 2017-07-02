#include <stdio.h>
#include <string.h>
#include "calc.h"

#define BUFSIZE 100


int buf[BUFSIZE];
int bufp = 0;

//exe 4-9 can push back EOF
int buf_char;


int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
	if(bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		if(c != '\n')
			buf[bufp++] = c;
}

//exe 4-7 push back string
void ungets(char *s)
{
	size_t i = strlen(s);

	while(i > 0)
	{
		ungetch(s[--i]);
	}
}

//exe 4-8 push back char
void unget(char c)
{
	if(buf_char != EOF)
	{
		buf_char = c;
	}
	else
	{
		printf("ungetch: too many characters\n");
	}
}

//exe 4-10
int get_line(char s[], int lim)
{
	int c, i;

	for(i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
	{
		s[i] = c;
	}

	if(c == '\n')
	{
		s[i] = c;
		++i;
	}

	s[i] = '\0';

	return i;
}