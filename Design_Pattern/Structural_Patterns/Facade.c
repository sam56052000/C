//
// Use a interface to cover all sub module
//
#include "stdio.h"
#include "srdlib.h"

void FlightContrller(void);
void PreFlightCheck(void);
void TurnOn_Engine(void);

void TakeOff(void);
{
	FlightContrller();

	PreFlightCheck();

	TurnOn_Engine();
}

void main(void)
{
	TakeOff();
}