#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "calc.h"

int getop(char s[])
{
	int i, c;

	while((s[0] = (c = getch())) == ' ' || c == '\t');

	s[1] = '\0';

	if(!isdigit(c) && c != '.')
		return c;

	i = 0;

	if(isdigit(c))
		while(isdigit(s[++i] = (c = getch())));

	if(c == '.')
		while(isdigit(s[++i] = (c = getch())));

	s[i] = '\0';

	if(c != EOF)
		ungetch(c);

	return NUMBER;
}


//4-7 exercise---------------------------
int getop_line(char s[])
{	
	char line_array[100];

	int array_length;

	array_length = get_line(line_array, 100);

	int i, j;

	for(i = 0, j = 0; i < array_length; i++)
	{
		if((line_array[i] >= '0' && line_array[i] <= '9') || line_array[i] == '.')
		{
			s[j++] = line_array[i];
		}
		else if(j != 0)
		{
			return line_array[i];
		}
	}

	return NUMBER;
}

//4-11 exercise---------------------------
int getop_static(char s[])
{
	int i, c;

	static int buf = EOF;

	if(buf == EOF)
	{
		while((s[0] = (c = getch())) == ' ' || c == '\t');

		s[1] = '\0';

		if(!isdigit(c) && c != '.')
			
		return c;
	}
	else
	{	
		int temp = buf;
		
		buf = EOF;

		return temp;
	}

	i = 0;

	if(isdigit(c))
		while(isdigit(s[++i] = (c = getch())));

	if(c == '.')
		while(isdigit(s[++i] = (c = getch())));

	s[i] = '\0';

	if(c != EOF && c != '\n')
		buf = c;

	return NUMBER;
}