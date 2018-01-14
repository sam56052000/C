//
// Create each Product by each factory.
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

typedef struct controller_creator
{
	class_controller (*Create)(void);

} controller_creator;

class_controller Create_raw_controller(void)
{
	class_controller instance = NULL;

	instance = malloc(sizeof(raw_controller_t));

	((raw_controller_t *)instance) -> param.gain = 1.0f;

	return instance;
}

class_controller Create_pitch_controller(void)
{
	class_controller instance = NULL;

	instance = malloc(sizeof(pitch_controller_t));

	((pitch_controller_t *)instance) -> param.gain = 1.0f;

	return instance;
}

void main(void)
{
	controller_creator raw_creator, pitch_creator;

	raw_creator.Create = Create_raw_controller;

	pitch_creator.Create = Create_pitch_controller;

	raw_controller_t *A;
	pitch_controller_t *B;

	A = (raw_controller_t *)raw_creator.Create();
	B = (pitch_controller_t *)pitch_creator.Create();

	printf("%.3f, %.3f\n", A -> param.gain, B -> param.gain);
}