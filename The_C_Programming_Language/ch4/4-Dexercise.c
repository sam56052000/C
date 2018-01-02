#include "stdio.h"
#include "string.h"

void reverse(char s[]);
void swap(char s[], int index1, int index2);

main()
{
	char test[10] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '\0'};

	printf("%d\n", strlen(test));

	reverse(test);

	
	printf("%s\n", test);
}

void reverse(char s[])
{
	int index1, index2;

	index1 = 0;
	index2 = strlen(s) - 1;

	swap(s, index1, index2);
}

void swap(char s[], int index1, int index2)
{
	char temp;

	temp = s[index1];
	s[index1] = s[index2];
	s[index2] = temp;

	index1 += 1;
	index2 -= 1;

	if(index1 < index2)
	{
		swap(s, index1, index2);
	}
}