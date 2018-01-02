#include "stdio.h"

#define swap(t,x,y) {t z=x;x=y;y=z;}

main()
{
	int x, y;

	x = 1;
	y = 2;

	swap(int ,x, y);

	printf("%d, %d\n", x, y);
}