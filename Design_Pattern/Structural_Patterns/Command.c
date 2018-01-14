//
// Set Command into object which can assign by invoker
//
#include "stdio.h"
#include "stdlib.h"

typedef struct position_t 
{
	float lon;
	float lat;
	float alt;

} position_t;

struct guidance_controller_t
{
	position_t now_cmd;

	position_t cmd_buffer[10];

	void (*add_trg)(position_t *);

	position_t * (*now_trg)(void);
};

void guidance_controller_add_trg(position_t * position)
{

}

position_t *guidance_controller_get_now_trg(void)
{
	static position_t now_cmd;

	return &now_cmd;
}

void flight_controller(position_t * position)
{

}

void main(void)
{
	struct guidance_controller_t guidance_controller;

	guidance_controller.add_trg = guidance_controller_add_trg;

	guidance_controller.now_trg = guidance_controller_get_now_trg;

	position_t new_cmd, *ref;

	guidance_controller.add_trg(&new_cmd);

	ref = guidance_controller.now_trg();

	flight_controller(ref);
}
