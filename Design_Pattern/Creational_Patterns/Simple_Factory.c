//
// Use one create function to handle all object creation.
//
#include "stdio.h"
#include "stdlib.h"

typedef struct class_controller *class_controller;

struct class_controller
{
	float gain;

	float max;

	float min;
};

typedef struct raw_controller_t
{
	struct class_controller param;

} raw_controller_t;

typedef struct pitch_controller_t
{
	struct class_controller param;

} pitch_controller_t;

class_controller CreateController(char input)
{
	class_controller instance = NULL;

	switch(input)
	{
		case 'R':
		{
			instance = malloc(sizeof(raw_controller_t));

			((raw_controller_t *)instance) -> param.gain = 1.0f;
		}
		break;

		case 'P':
		{
			instance = malloc(sizeof(pitch_controller_t));

			((pitch_controller_t *)instance) -> param.gain = 1.0f;
		}
		break;
	}

	return instance;
}

void main(void)
{
	raw_controller_t *A;
	pitch_controller_t *B;

	A = (raw_controller_t *)CreateController('R');
	B = (pitch_controller_t *)CreateController('P');

	printf("%.3f, %.3f\n", A -> param.gain, B -> param.gain);
}