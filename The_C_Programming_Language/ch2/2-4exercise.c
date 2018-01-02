//Delete character in s1 which match s2
#include <stdio.h>

#define MAXLEN 10

void squeeze_alt(char [], char);

main()
{
	char s1[MAXLEN], s2[MAXLEN];
	char c, ind = 0;
	int len_s1 = 0, len_s2 = 0;

	while((c = getchar()) != '\n' && len_s1 < MAXLEN)
	{
		s1[len_s1++] = c;
	}
	s1[len_s1] = '\0';

	while((c = getchar()) != '\n' && len_s2 < MAXLEN)
	{
		s2[len_s2++] = c;
	}
	s2[len_s2] = '\0';

	while(s2[ind] != '\0')
	{
		squeeze_alt(s1, s2[ind]);
		ind++;
	}

	printf("%s\n", s1);
}

void squeeze_alt(char s[], char ss)
{
	int i, j;

	for(i = j = 0; s[i] != '\0'; i++)
		if(s[i] != ss)
			s[j++] = s[i];
	s[j] = '\0';
}