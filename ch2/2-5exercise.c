//Return the first location in s1 from s2 occur 
#include <stdio.h>

#define MAXLEN 10

int squeeze_alt(char [], char);

main()
{
	char s1[MAXLEN], s2[MAXLEN];
	char c, ind = 0;
	int len_s1 = 0, len_s2 = 0, ans = -1;

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
		if((ans = squeeze_alt(s1, s2[ind])) != -1)
			break;
		ind++;
	}

	printf("%d\n", ans);
}

int squeeze_alt(char s[], char ss)
{
	int i, f = -1;

	for(i = 0; s[i] != '\0'; i++)
		if(s[i] == ss)
		{
			f = i;
			break;
		}
			
	return f;
}