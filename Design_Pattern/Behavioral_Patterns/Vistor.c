#include "stdio.h"
#include "stdlib.h"

#define P_MODE 8
#define V_MODE 9
#define T_MODE 10

typedef struct Motor_t Motor_t;
typedef struct Run_t Run_t;

struct Motor_t
{
	int axis;
	int mode;
};

struct Run_t
{
	void (*Pmode)(Motor_t *);
	void (*Vmode)(Motor_t *);
	void (*Tmode)(Motor_t *);
};

void Pmode(Motor_t *motor)
{
	motor -> mode = P_MODE;

	printf("Axis%d in Position Mode\n", motor -> axis);
}

void Vmode(Motor_t *motor)
{
	motor -> mode = V_MODE;
	
	printf("Axis%d in Velocity Mode\n", motor -> axis);
}

void Tmode(Motor_t *motor)
{
	motor -> mode = T_MODE;
	
	printf("Axis%d in Torque Mode\n", motor -> axis);
}

void main(void)
{
	Run_t run_mode;
	run_mode.Pmode = Pmode;
	run_mode.Vmode = Vmode;
	run_mode.Tmode = Tmode;

	Motor_t A, B, C;

	A.axis = 1;
	B.axis = 2;
	C.axis = 3;

	run_mode.Pmode(&A);
	run_mode.Vmode(&B);
	run_mode.Tmode(&C);
}