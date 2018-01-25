#include "stdio.h"
#include "stdlib.h"

typedef struct part1_t
{
	int a;

} part1_t;

typedef struct part2_t
{
	int b;
	
} part2_t;

typedef struct asm_t
{
	part1_t *p1;
	part2_t *p2;
	
} asm_t;

part1_t *Create_part1(void)
{
	return malloc(sizeof(part1_t));
}

part2_t *Create_part2(void)
{
	return malloc(sizeof(part2_t));
}

asm_t *Builder(void)
{
	asm_t *obj;

	obj = malloc(sizeof(asm_t));

	obj -> p1 = Create_part1();
	obj -> p2 = Create_part2();

	return obj;
}

void main(void)
{
	asm_t *obj;

	obj = Builder();

	obj -> p1 -> a = 1;

	printf("%d\n", obj -> p1 -> a);
}