#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

class Date
{
public:
	int day;
	int month;
	int year;


	Date() {};

	Date(int day_tmp, int month_tmp, int year_tmp)
	{
		day = day_tmp;
		month = month_tmp;
		year = year_tmp;
	};
};

