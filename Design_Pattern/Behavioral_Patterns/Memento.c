#include "stdio.h"
#include "stdlib.h"

typedef struct position_t position_t;
typedef struct save_t save_t;

struct position_t
{
	float lat;
	float lon;
	float alt;
};

position_t *CreatePosition(float lat, float lon, float alt)
{
	position_t *instance;

	instance = malloc(sizeof(position_t));

	instance -> lat = lat;
	instance -> lon = lon;
	instance -> alt = alt;

	return instance;
}

struct save_t 
{
	position_t data;
};

save_t *SaveData(position_t *pos)
{
	save_t *instance;

	instance = malloc(sizeof(save_t));

	instance -> data.lat = pos -> lat;
	instance -> data.lon = pos -> lon;
	instance -> data.alt = pos -> alt;

	return instance;
}

position_t *LoadData(save_t *sav)
{
	position_t *instance;

	instance = malloc(sizeof(position_t));

	instance -> lat = sav -> data.lat;
	instance -> lon = sav -> data.lon;
	instance -> alt = sav -> data.alt;

	free(sav);

	return instance;
}

void main(void)
{
	position_t *A, *B;
	save_t *sav;

	A = CreatePosition(1.0f, 1.0f, 1.0f);

	sav = SaveData(A);

	B = LoadData(sav);

	printf("A=%.3f, B=%.3f, sav=%.3f\n", A -> lat, B -> lat, sav -> data.lat);
}