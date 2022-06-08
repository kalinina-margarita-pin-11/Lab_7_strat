#include "Storage.h"

Storage::Storage(string name_tmp, double price_tmp, int amount_tmp, int num_s_tmp, int day_tmp, int month_tmp, int year_tmp)
{
	name = name_tmp;
	price = price_tmp;
	amount = amount_tmp;
	num_s = num_s_tmp;
	date.day = day_tmp;
	date.month = month_tmp;
	date.year = year_tmp;
};



//Getters
string Storage::get_name()
{
	return name;
}
double Storage::get_price()
{
	return price;
}
int Storage::get_amount()
{
	return amount;
}
int Storage::get_num_s()
{
	return num_s;
}
int Storage::get_date_day()
{
	return date.day;
}
int Storage::get_date_month()
{
	return date.month;
}
int Storage::get_date_year()
{
	return date.year;
}

//Setters
void Storage::set_name(string name_tmp)
{
	this->name = name_tmp;
};
void Storage::set_price(double price_tmp)
{
	this->price = price_tmp;
};
void Storage::set_amount(int amount_tmp)
{
	amount = amount_tmp;
};
void Storage::set_num_s(int num_s_tmp)
{
	num_s = num_s_tmp;
};
void Storage::set_date_day(int day_tmp)
{
	date.day = day_tmp;
};
void Storage::set_date_month(int month_tmp)
{
	date.month = month_tmp;
};
void Storage::set_date_year(int year_tmp)
{
	date.year = year_tmp;
};



