#include <stdio.h>

#define MAXLINE 100

void get_string(char s[]);
void expand(char s1[], char s2[]);

main()
{
	char s1[MAXLINE],s2[MAXLINE];

	get_string(s1);
	expand(s1, s2);

	printf("%s\n", s2);
}

void get_string(char s[])
{	
	char c;

	int i = 0;

	while((c = getchar()) != '\n')
	{
		s[i++] = c;
	}
	
	s[i] = '\0';
}

void expand(char s1[], char s2[])
{	
	int i = 0,j = 0;
	char first, last, print;

	while(s1[i] != '\0')
	{
		s2[j++] = s1[i++];

		if(s1[i] == '-')
		{
			first = s1[i - 1];
			last = s1[i + 1];

			while(first < last - 1)
			{
				s2[j++] = ++first;
			}

			i++;
		}
	}

	s2[j] = '\0';
}