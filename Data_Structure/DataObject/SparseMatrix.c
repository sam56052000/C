#include "stdio.h"
#include "stdlib.h"

typedef struct Term_t
{
	int row;
	int col;
	int value;

} Term_t;

void FastTranspose(Term_t a[], Term_t b[]);

main()
{
	Term_t a[] = 
	{
		{2,2,4},
		{0,0,1},
		{0,1,2},
		{1,0,3},
		{1,1,4}
	};

	Term_t b[5];

	FastTranspose(a, b);

	printf("%d %d\n%d %d\n", a[1].value, a[2].value, a[3].value, a[4].value);
	printf("%d %d\n%d %d\n", b[1].value, b[2].value, b[3].value, b[4].value);
}

void FastTranspose(Term_t a[], Term_t b[])
{
	int *rowTerms = (int *)(calloc(a[0].col + 1, sizeof(int)));
	int i, j = 1, numCols = a[0].col, numTerms = a[0].value;

	b[0].row = numCols;
	b[0].col = a[0].row;
	b[0].value = numTerms;

	if(numTerms > 0)
	{
		for(i = 1; i <= numTerms; i++)
			rowTerms[a[i].col + 1]++;

		rowTerms[0] = 1;

		for(i = 1; i <= numCols; i++)
			rowTerms[i] += rowTerms[i - 1];

		for(i = 1; i <= numTerms; i++)
		{
			j = rowTerms[a[i].col]++;

			b[j].row = a[i].col;
			b[j].col = a[i].row;
			b[j].value = a[i].value;
		}
	}
}