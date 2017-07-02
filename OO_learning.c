#include "stdio.h"

typedef struct readvalue_t Readvalue_t;
typedef int (*func_t)(Readvalue_t *);

int Readvalue(Readvalue_t *);
int Getvalue(void);
void Init_Readvalue_t(Readvalue_t *);

enum
{
	SM0 = 0,
	SM1,
	SM2,
	SM3,
	enum_size
};

struct readvalue_t
{
	int state;

	func_t read, write, get;

	int (*got)();
};

Readvalue_t EMIF[enum_size];

void main(void)
{
	Init_Readvalue_t(&EMIF[SM0]);

	printf("%d\n", EMIF.got());
}

void Init_Readvalue_t(Readvalue_t * value_name)
{
	value_name -> state = 0;

	value_name -> read = Readvalue;

	value_name -> got = Getvalue;
}

int Readvalue(Readvalue_t * value_name)
{
	if(value_name -> state == 0)
	{
		//Read
		value_name -> state = 1;

		return 0;
	}
	else
	{
		//get

		return 1;
	}
}

int Getvalue(void)
{
	return 9487;
}