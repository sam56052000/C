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