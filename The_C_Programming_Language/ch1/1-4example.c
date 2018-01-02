//Use Define
#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

main()
{
	int f;

	for(f = LOWER; f <= UPPER; f += STEP)
	{
		printf("%3d %6.1f\n", f, (5.0f / 9.0f) * (f - 32));
	}
}