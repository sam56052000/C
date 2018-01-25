#include "stdio.h"
#include "stdlib.h"

typedef struct GPS_error_t
{
	float lon;
	float lat;

} GPS_error_t;

typedef struct error_m_t
{
	float N;
	float E;

} error_m_t;

GPS_error_t *GPS_Receiver(void)
{

}

error_m_t *Adapter(GPS_error_t *gps_error)
{

}

void flight_controller(error_m_t *error_m)
{

}

void main(void)
{
	flight_controller(Adapter(GPS_Receiver()));
}