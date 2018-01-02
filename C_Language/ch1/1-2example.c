//Printf Temperature
#include <stdio.h>

main()
{
	float f, c;
	float low, up, step;

	f = 0;
	low = 0;
	up = 300;
	step = 20;

	while(f <= up)
	{
		c = (f - 32) * 5 / 9;
		printf("f = %3.0f, c = %.2f\n", f, c);
		f += step;
	}
}