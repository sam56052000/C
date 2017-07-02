//Return x with n bits that begin at position p set to rightmost n bits of y
#include <stdio.h>

int setbits(int x, int y, int p, int n);

main()
{
	int x, y, p = 9, n = 3;

	x = 0xFFFF;
	y = 0xFFF1;

	x = setbits(x,y,p,n);
	printf("%x\n", x);
}

int setbits(int x, int y, int p, int n)
{	
	int x_r;

	y -= (y >> n) << n;

	x_r = x - ((x >> (p- n)) << (p- n));

	x = ((x >> p) << p) | x_r;

	x = x | (y << (p - n));

	return x;
}