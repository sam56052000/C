#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct sextype_t
{
	enum
	{
		female,
		male

	} sextype;

	union
	{
		int children;
		int beard;

	} sextype_union;

} sextype_t;

typedef struct date_t
{
	int day;
	int month;
	int year;

} date_t;

typedef struct martial_t
{
	enum
	{
		single,
		married,
		widowed,
		divorced

	} martial;

	union
	{
		struct
		{
			date_t married_day;

		} married_Info;

		struct
		{
			date_t married_day;
			date_t death_day;

		} widowed_Info;

		struct
		{
			date_t divorced_day;

			int times;

		} divorced_Info;


	} Info;

} martial_t;


typedef struct humanBeing_t
{
	char name[10];
	int age;
	float salary;

	date_t		birthday;
	sextype_t 	sexInfo;
	martial_t	marryInfo;

} humanBeing_t;

main()
{
	humanBeing_t person;

	strcpy(person.name, "james");

	person.age = 25;

	person.salary = 700.0f;

	person.birthday.year = 1992;
	person.birthday.month = 8;
	person.birthday.day = 9;

	person.sexInfo.sextype = male;
	person.sexInfo.sextype_union.beard = 10;

	person.marryInfo.martial = divorced;
	person.marryInfo.Info.divorced_Info.divorced_day.year = 1992;
}