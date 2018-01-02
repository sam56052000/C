//Return x with the n bit s that begin at position p inverted
#include <stdio.h>

int invert(int x, int p, int n);

main()
{
	int x = 0xFFFF, p = 9, n = 3;

	x = invert(x, p, n);

	printf("%x\n", x);

}

int invert(int x, int p, int n)
{
	int x_r, mask;

	mask = ~((~0 >> n) << n) << (p-n);

	x = ~(x & mask) & x;

	return x;
}