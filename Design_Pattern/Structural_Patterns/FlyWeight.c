#include "stdio.h"
#include "stdlib.h"

typedef struct Index_t Index_t;
typedef struct SubIndex_t SubIndex_t;

struct Index_t
{	
	int par;

	SubIndex_t *sub;
};

struct SubIndex_t
{
	int sub1;
	int sub2;
};

void main(void)
{
	Index_t A, B;

	SubIndex_t C;

	A.sub = &C;
	B.sub = &C;

	A.sub -> sub1 = 1;
	
	printf("A=%d, B=%d\n", A.sub -> sub1, B.sub -> sub1);
}