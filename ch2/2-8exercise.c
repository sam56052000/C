//Return the value of the integer x rotated to the right by n position
#include <stdio.h>

main()
{
	int x = 0x0F0F0F0F, n = 5;

	x = (x << n) | (x >> (32 - n)); 

	printf("%x\n", x);
}