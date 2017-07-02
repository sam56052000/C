#include <stdio.h>
#include <stdlib.h>
#include "calc.h"
#include <math.h>

#define MAXOP 100

int main(void)
{
	// char *aa = "hello, world.  this is a test.";
	// int c;

	// ungets(aa);
	// while ((c = getch()) != EOF)
 	// putchar(c); 

	//----------------

	int type;
	double op2;
	char s[MAXOP];

	char *string = "ch4 exp";
	printf("%s\n", string);

	char command = 0;
	double print_num;

	while((type = getop_static(s)) != EOF)
	{	
		switch(type)
		{
			case NUMBER:
				push(atof(s));
				break;

			case '+':
				push(pop() + pop());
				break;

			case '*':
				push(pop() * pop());
				break;

			case '-':
				op2 = pop();

				push(pop() - op2);
				break;

			case '/':
				op2 = pop();
				if(op2 != 0.0f)
				{
					push(pop() / op2);
				}
				else
				{
					printf("error: zero divisor\n");
				}

				break;

			case '\n':
				if(command == 0)
				{
					print_num = pop();
					printf("\t%.8g\n", print_num);
				}
				else
				{
					command = 0;
				}
				break;

			//4-3 exercise---------------------------
			case '%':
				op2 = pop();
				if(op2 != 0.0f)
				{	
					push((int)(pop()) % (int)(op2));
				}
				else
				{
					printf("error: zero divisor\n");
				}
				break;

			//4-4 exercise---------------------------
			case 'S':
				swap_top2();
				command = 1;
				break;

			case 'C':
				clear_stack();
				command = 1;
				break;

			case 'R':
				printf("\t%.8g\n", print_num);
				command = 1;
				break;

			//4-5 exercise---------------------------
			case 'P':
				op2 = pop();
				push(pow(pop(), op2));
				break;

			case 'E':
				printf("%f\n", exp(pop()));
				command = 1;
				break;

			//4-6 exercise---------------------------
			case 'T':
				printf("%f\n", print_top());
				command = 1;
				break;

			default:
				printf("error: unknown command %s\n", s);
				break;
		}
	}

	return 0;
}