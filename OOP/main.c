#include "OOP_learning.h"

#define USING_STRUCT	0
#define USING_MACRO		1

INIT_STRUCT_A(Father);
INIT_STRUCT_B_INHER_A(Child1, FUNC3_1);
INIT_STRUCT_B_INHER_A(Child2, FUNC3_2);

void main(void)
{
	int test_num = USING_MACRO;

	switch(test_num)
	{
		case USING_STRUCT:
		{
			Init_Object(obj_1);
			Init_Child(child_1,method_3_1);
			Init_Child(child_2,method_3_2);

			obj_1.a = 8;
			obj_1.b = 2;

			child_1.Inhr(Object_t).a = 8;
			child_1.Inhr(Object_t).b = 2;
			child_2.Inhr(Object_t).a = 8;
			child_2.Inhr(Object_t).b = 2;

			printf("%d\n", ADD(obj_1));
			printf("%d\n", SUB(obj_1));

			printf("%d\n", USE_METHOD3(child_1));
			printf("%d\n", USE_METHOD3(child_2));
		}

		case USING_MACRO:
		{
			Father_a = 8;
			Father_b = 2;

			Child1_A_a = 8;
			Child1_A_b = 2;

			Child2_A_a = 8;
			Child2_A_b = 2;

			printf("%d\n", Father_func1());
			printf("%d\n", Father_func2());
			printf("%d\n", Child1_func3());
			printf("%d\n", Child2_func3());
		}
	}


}