#include "stdio.h"
#include "ctype.h"
#include "string.h"

#define char_lim 32

void getword(char w[]);

void main(void)
{
	//printf("\033[1;31mRed\n");
	
	char word[char_lim];

	getword(word);

	printf("%s\n", word);
}


void getword(char w[])
{
	char c;

	int i = 0, len = strlen(w);

	while((c = getch()) == ' ' | c == '\t');

	if(c != EOF && c != '\n' && c != '#')
		w[i++] = c;

	if(!isalpha(c) && c != '_')
	{
		w[0] = '\0';

		return;
	}

	for(; --len; i++)
	{
		if(!isalnum(w[i] = getch()))
		{
			if(w[i] != '_')
			{
				ungetch(w[i]);
				break;
			}
		}
	}

	w[i] = '\0';
}