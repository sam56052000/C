//bits count
#include "stdio.h"

main()
{
	int x = 0xAA;

	int b = 0;

	for(b = 0; x != 0; x &= (x - 1))
		b++;

	printf("%d\n", b);
}

/* 

loop 1 : 10101010 & 10101001 = 10101000
loop 2 : 10101000 & 10100111 = 10100000
loop 3 : 10100000 & 10011111 = 10000000
loop 4 : 10000000 & 01111111 = 00000000

break -> b = 4

*/
	