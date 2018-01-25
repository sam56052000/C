#include "stdio.h"
#include "stdlib.h"

typedef struct interpreter_t interpreter_t;

struct interpreter_t
{
	void (*interprete)(int []);
};

void process_16bit(int memory[])
{
	printf("data = %x\n", memory[0]);
}

void process_32bit(int memory[])
{
	int a = (memory[1] << 16) | (memory[0]);

	printf("data = %x\n", a);
}

void main(void)
{
	int memory[] = {0x1234, 0x5678};

	interpreter_t type1, type2;

	type1.interprete = process_16bit;
	type2.interprete = process_32bit;

	type1.interprete(memory);
	type2.interprete(memory);
}