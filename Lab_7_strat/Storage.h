#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Date.h"
using namespace std;

class Storage
{
protected:
	string name;
	double price;
	int amount;
	int num_s;
	Date date;
public:
	static int count;
	Storage() {};
	Storage(string name_tmp, double price_tmp, int amount_tmp, int num_s_tmp, int day_tmp, int month_tmp, int year_tmp);
	string get_name();
	void set_name(string name_tmp);
	double get_price();
	void set_price(double price_tmp);
	int get_amount();
	void set_amount(int amount_tmp);
	int get_num_s();
	void set_num_s(int num_s_tmp);
	int get_date_day();
	void set_date_day(int day_tmp);
	int get_date_month();
	void set_date_month(int month_tmp);
	int get_date_year();
	void set_date_year(int year_tmp);
	friend bool operator> (Storage& store1, Date base);
	Storage& operator= (Storage& store_tmp)
	{
		name = store_tmp.get_name();
		price = store_tmp.get_price();
		amount = store_tmp.get_amount();
		num_s = store_tmp.get_num_s();
		date.day = store_tmp.get_date_day();
		date.month = store_tmp.get_date_month();
		date.year = store_tmp.get_date_year();
		return *this;
	}
};
