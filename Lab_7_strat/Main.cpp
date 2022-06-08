#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>
#include <vector>
#include <list>
#include <deque>
#include "Storage.h"
#include "Date.h"
using namespace std;
int read_int()
{
	string buff;
	int number;
	int i, flag = 0;
	while (flag == 0)
	{
		getline(cin, buff);
		flag = 1;
		if (buff == "") flag = 0;
		for (i = 0; i < buff.size(); i++)
		{
			if (buff[i] < '0' || buff[i]>'9')
			{
				flag = 0;
				break;
			}
		}
		if (flag == 1) break;
		cout << "Enter integer number" << endl;
	}
	number = stoi(buff);
	return number;
}

string read_string()
{
	string s;
	int flag = 0;
	while (flag == 0)
	{
		getline(cin, s);

		if (s == "")
			cout << "Enter something" << endl;
		else flag = 1;


	}


	return s;
}

double read_double()
{
	string buff;
	double number;
	int i, flag = 0, flagpoint = 0;
	while (flag == 0)
	{
		getline(cin, buff);

		flag = 1;
		if (buff == "") flag = 0;
		flagpoint = 0;
		for (i = 0; i < buff.size(); i++)
		{
			if (buff[i] < '0' || buff[i]>'9')
			{

				if ((flagpoint == 0) && (buff[i] == '.'))
				{
					flagpoint = 1;
					continue;
				}
				flag = 0;
				break;
			}
		}
		if (flag == 1) break;
		cout << "Enter float number" << endl;
	}
	number = stof(buff);
	return number;
}

void read_date(int& day, int& month, int& year)
{
	int year_tmp = 0;
	while ((year_tmp < 1980) || (year_tmp > 2050))
	{
		cout << "Input the year: "; year_tmp = read_int();
	}

	int month_tmp = 0;
	while ((month_tmp < 1) || (month_tmp > 12))
	{
		cout << "Input the month: ";
		month_tmp = read_int();
	}

	int day_tmp = 0;
	while ((day_tmp < 1) || (day_tmp > 31))
	{
		cout << "Input the day: ";
		day_tmp = read_int();
		if (((month_tmp == 4) || (month_tmp == 6) || (month_tmp == 9) || (month_tmp == 11)) && (day_tmp > 30)) day_tmp = 0;
		if ((month_tmp == 2) && (day_tmp > 29) && ((year_tmp % 400 == 0) || ((year_tmp % 4 == 0) && (year_tmp % 100 != 0))))
		{
			day_tmp = 0;
		}
		if ((month_tmp == 2) && (day_tmp > 28) && !((year_tmp % 400 == 0) || ((year_tmp % 4 == 0) && (year_tmp % 100 != 0))))
		{
			day_tmp = 0;
		}

		day = day_tmp;
		month = month_tmp;
		year = year_tmp;
	}
}

void init_storage(Storage*& store, int& N)
{
	struct Storage* store_tmp;
	store_tmp = new struct Storage[N + 1];
	for (int i = 0; i < N; i++)
	{
		store_tmp[i] = store[i];
	}
	delete[] store;

	int i;
	store = new struct Storage[N + 1];
	cout << "Input product name: "; string name = read_string();
	cout << "Input product price: "; double price = read_double();
	cout << "Input product amount: ";
	int amount = read_int();
	while (amount == 0)
	{
		cout << "Input product amount: ";
		amount = read_int();

	}

	cout << "Input number of section: "; int num_s = read_int();
	cout << "Input the exploration date of product: " << endl;
	cout << "Input the year: "; int year = read_int();


	int month = 0;
	while ((month < 1) || (month > 12))
	{
		cout << "Input the month: ";
		month = read_int();
	}


	int day = 0;
	while ((day < 1) || (day > 31))
	{
		cout << "Input the day: ";
		day = read_int();
		if ((month == 2) && (day > 29) && ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0))))
		{
			day = 0;
		}
		if ((month == 2) && (day > 28) && !((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0))))
		{
			day = 0;
		}

	}




	Storage store_new(name, price, amount, num_s, day, month, year);
	store_tmp[N] = store_new;
	N = N + 1;
	for (int i = 0; i < N; i++)
	{
		store[i] = store_tmp[i];

	}
	delete[] store_tmp;
}

void init_storage(vector <Storage> &store, int& N)
{
	vector <Storage> store_tmp(N + 1);
	for (int i = 0; i < N; i++)
	{
		store_tmp[i] = store[i];
	}
	store.clear();

	int i;
	store.resize(N+1);
	cout << "Input product name: "; string name = read_string();
	cout << "Input product price: "; double price = read_double();
	cout << "Input product amount: ";
	int amount = read_int();
	while (amount == 0)
	{
		cout << "Input product amount: ";
		amount = read_int();

	}
	cout << "Input number of section: "; int num_s = read_int();
	cout << "Input the exploration date of product: " << endl;
	cout << "Input the year: "; int year = read_int();
	int month = 0;
	while ((month < 1) || (month > 12))
	{
		cout << "Input the month: ";
		month = read_int();
	}
	int day = 0;
	while ((day < 1) || (day > 31))
	{
		cout << "Input the day: ";
		day = read_int();
		if ((month == 2) && (day > 29) && ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0))))
		{
			day = 0;
		}
		if ((month == 2) && (day > 28) && !((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0))))
		{
			day = 0;
		}
	}
	Storage store_new(name, price, amount, num_s, day, month, year);
	store_tmp[N] = store_new;
	N = N + 1;
	for (int i = 0; i < N; i++)
	{
		store[i] = store_tmp[i];
	}
	store_tmp.clear();
}

void init_storage_0(Storage& store)
{
	int amount = 0;
	while (amount == 0)
	{
		cout << "Input product amount: ";
		amount = read_int();
	}
	cout << "Input number of section: "; int num_s = read_int();
	int day, month, year;
	cout << "Input the exploration date of product: " << endl;
	read_date(day, month, year);
	string name = "-1";
	double price = -1;
	Storage store_tmp(name, price, amount, num_s, day, month, year);
	store = store_tmp;
}

istream& operator >> (istream& in, Storage& store)
{
	init_storage_0(store);
	return in;
}

void init_storage_1(Storage*& store, int& N, string name, double price)
{
	struct Storage* store_tmp;
	store_tmp = new struct Storage[N + 1];
	for (int i = 0; i < N; i++)
	{
		store_tmp[i] = store[i];
	}
	delete[] store;

	store = new struct Storage[N + 1];

	Storage store_new;
	cin >> store_new;
	store_new.set_name(name);
	store_new.set_price(price);
	store_tmp[N] = store_new;
	N = N + 1;
	for (int i = 0; i < N; i++)
	{
		store[i] = store_tmp[i];

	}
	delete[] store_tmp;
}

void init_storage_1(Storage& store, string name, double price)
{
	Storage store_new;
	cin >> store_new;
	store_new.set_name(name);
	store_new.set_price(price);
	store = store_new;
}

void init_storage_1(vector <Storage> &store, int& N, string name, double price)
{
	vector <Storage> store_tmp(N+1);
	for (int i = 0; i < N; i++)
	{
		store_tmp[i] = store[i];
	}
	store.clear();
	store.resize(N + 1);
	Storage store_new;
	cin >> store_new;
	store_new.set_name(name);
	store_new.set_price(price);
	store_tmp[N] = store_new;
	N = N + 1;
	for (int i = 0; i < N; i++)
	{
		store[i] = store_tmp[i];

	}
	store_tmp.clear();
}

void init_storage_2(vector <Storage> &storage, int& N_rage)
{
	string name_tmp;
	int amount_tmp;
	double price_tmp;
	vector <Storage> storage_tmp(N_rage);
	int flag = 0;
	cout << "Enter product name: ";
	name_tmp = read_string();
	cout << "Enter product price: ";
	price_tmp = read_double();
	for (int i = 0; i < N_rage; i++)
	{
		if ((storage[i].get_price() == price_tmp) && (storage[i].get_name() == name_tmp))
		{
			flag = 1;
			amount_tmp = storage[i].get_amount();
			storage[i].set_amount(amount_tmp + 1);
		}
	}
	if (flag == 0)
	{
		init_storage_1(storage, N_rage, name_tmp, price_tmp);
	}
}

void print(Storage*& store, int i)
{


	cout << "Product name: " << store[i].get_name() <<
		"\nInput product price: " << store[i].get_price() <<
		"\nInput product amount: " << store[i].get_amount() <<
		"\nInput number of section: " << store[i].get_num_s() <<
		"\nThe exploration date of product: " << store[i].get_date_day() << "/" <<
		store[i].get_date_month() << "/" << store[i].get_date_year() << endl;
};

void print(vector <Storage> store, int i)
{
	//vector<Storage>::iterator p=store.begin();

	cout << "Product name: " << store[i].get_name() <<
		"\nInput product price: " << store[i].get_price() <<
		"\nInput product amount: " << store[i].get_amount() <<
		"\nInput number of section: " << store[i].get_num_s() <<
		"\nThe exploration date of product: " << store[i].get_date_day() << "/" <<
		store[i].get_date_month() << "/" << store[i].get_date_year() << endl;
};

void find_by_section(Storage*& store, int N)
{
	int i, flag = 0;
	int number;
	cout << "Input number of section: " << endl;
	number = read_int();

	for (i = 0; i < N; i++)
	{
		if (store[i].get_num_s() == number)
		{
			if (flag == 0) cout << "The product you are looking for:" << endl;
			print(store, i);
			flag = 1;
		}
	}
	if (flag == 0) cout << "There isn't any product with this number of section" << endl;
};

void find_by_section(vector <Storage> store, int N)
{
	int i, flag = 0;
	int number;
	cout << "Input number of section: " << endl;
	number = read_int();

	for (i = 0; i < N; i++)
	{
		if (store[i].get_num_s() == number)
		{
			if (flag == 0) cout << "The product you are looking for:" << endl;
			print(store, i);
			flag = 1;
		}
	}
	if (flag == 0) cout << "There isn't any product with this number of section" << endl;
};

void sort_by_price(Storage*& store, int N)
{
	int i, k;
	struct Storage store_switch;
	struct Storage* store_tmp;
	store_tmp = new struct Storage[N];
	for (i = 0; i < N; i++)
	{
		store_tmp[i] = store[i];
	}
	for (k = 1; k < N; k++)
		for (i = 0; i < N - 1; i++)
			if (store_tmp[i].get_price() < store_tmp[i + 1].get_price())
			{
				store_switch = store_tmp[i];
				store_tmp[i] = store_tmp[i + 1];
				store_tmp[i + 1] = store_switch;
			}



	for (i = 0; i < N; i++)
	{
		cout << "Product with number " << i + 1 << endl;
		cout << endl;
		print(store_tmp, i);
		cout << endl;
	}

}

void sort_by_price(vector <Storage> store, int N)
{
	int i, k;
	//struct Storage store_switch;
	vector <Storage> store_tmp(N);
	vector <Storage> store_switch(1);
	for (i = 0; i < N; i++)
	{
		store_tmp[i] = store[i];
	}
	for (k = 1; k < N; k++)
		for (i = 0; i < N - 1; i++)
			if (store_tmp[i].get_price() < store_tmp[i + 1].get_price())
			{
				store_switch[0] = store_tmp[i];
				store_tmp[i] = store_tmp[i + 1];
				store_tmp[i + 1] = store_switch[0];
			}

	for (i = 0; i < N; i++)
	{
		cout << "Product with number " << i + 1 << endl;
		cout << endl;
		print(store_tmp, i);
		cout << endl;
	}

}

void sort_by_amount(vector <Storage> store, int N)
{
	int i, k;
	vector <Storage> store_tmp(N);
	vector <Storage> store_switch(1);
	for (i = 0; i < N; i++)
	{
		store_tmp[i] = store[i];
	}
	for (k = 1; k < N; k++)
		for (i = 0; i < N - 1; i++)
			if (store_tmp[i].get_amount() < store_tmp[i + 1].get_amount())
			{
				store_switch[0] = store_tmp[i];
				store_tmp[i] = store_tmp[i + 1];
				store_tmp[i + 1] = store_switch[0];
			}

	for (i = 0; i < N; i++)
	{
		cout << "Product with number " << i + 1 << endl;
		cout << endl;
		print(store_tmp, i);
		cout << endl;
	}

}

bool operator > (Storage& store, Date base)
{
	if (store.get_date_year() < base.year)
	{
		return false;
	}
	else if ((store.get_date_year() == base.year) && (store.get_date_month() < base.month))
	{
		return false;
	}
	else if ((store.get_date_year() == base.year) && (store.get_date_month() == base.month) && (store.get_date_day() < base.day))
	{
		return false;
	}


	else if (store.get_date_year() > base.year)
	{
		return true;
	}

	else if ((store.get_date_year() == base.year) && (store.get_date_month() > base.month))
	{
		return true;
	}

	else if ((store.get_date_year() == base.year) && (store.get_date_month() == base.month) && (store.get_date_day() >= base.day))
	{
		return true;
	}


}

void find_by_data(Storage*& store, int N)
{
	int i, flag = 0;
	int number;
	cout << "Input the data: " << endl;

	cout << "Input the day: ";
	int day = read_int();
	while ((day < 1) || (day > 31))
	{
		cout << "Input the day: ";
		day = read_int();
	}

	cout << "Input the month: ";
	int month = read_int();
	while ((month < 1) || (month > 12))
	{
		cout << "Input the month: ";
		month = read_int();
	}
	cout << "Input the year: "; int year = read_int();

	Date base_tmp(day, month, year);
	for (int i = 0; i < N; i++)
	{
		if (store[i] > base_tmp)
		{
			cout << endl;
			cout << "This product is expired:" << endl;
			print(store, i);
		}


	}


}

void find_expired_by_date(vector <Storage> store, int N)
{
	Storage store_tmp;
	int i, flag = 0;
	int number;
	cout << "Input the data: " << endl;

	cout << "Input the day: ";
	int day = read_int();
	while ((day < 1) || (day > 31))
	{
		cout << "Input the day: ";
		day = read_int();
	}

	cout << "Input the month: ";
	int month = read_int();
	while ((month < 1) || (month > 12))
	{
		cout << "Input the month: ";
		month = read_int();
	}
	cout << "Input the year: "; int year = read_int();

	Date base_tmp(day, month, year);
	for (int i = 0; i < N; i++)
	{
		if (store[i] > base_tmp)
		{
			cout << endl;
			cout << "This product is expired:" << endl;
			print(store, i);
		}
	}
}

void find_by_date(vector <Storage> store, int N)
{
	Storage store_tmp;
	int i, flag = 0;
	int number, flag_found = 0;
	int day_tmp, month_tmp, year_tmp;
	read_date(day_tmp, month_tmp, year_tmp);

	for (int i = 0; i < N; i++)
	{
		if ((store[i].get_date_day() == day_tmp) && (store[i].get_date_month() == month_tmp) && (store[i].get_date_year() == year_tmp))
		{
			cout << endl;
			if (flag_found == 0) cout << "The product you are looking for:" << endl;
			flag_found = 1;
			print(store, i);
		}
	}
	if (flag_found == 0) cout << "There is no product with that date" << endl;
}

void add_to_begin(vector <Storage>& store, int& N)
{
	Storage store_add;
	string name_tmp;
	double price_tmp;
	int amount_tmp;
	cout << "Enter product name: ";
	name_tmp = read_string();
	cout << "Enter product price: ";
	price_tmp = read_double();
	int flag = 0;
	for (int i = 0; i < N; i++)
	{
		if ((store[i].get_price() == price_tmp) && (store[i].get_name() == name_tmp))
		{
			flag = 1;
			amount_tmp = store[i].get_amount();
			store[i].set_amount(amount_tmp + 1);
		}
	}
	if (flag == 0)
	{
		init_storage_1(store_add, name_tmp, price_tmp);
		vector <Storage> store_tmp(N + 1);
		for (int i = 0; i < N; i++)
		{
			store_tmp[i + 1] = store[i];
		}
		store_tmp[0] = store_add;
		store.clear();
		store.resize(N + 1);
		N++;
		for (int i = 0; i < N; i++)
		{
			store[i] = store_tmp[i];
		}
		
	}
	
}

void add_to_end(vector <Storage>& store, int& N)
{
	Storage store_add;
	string name_tmp;
	double price_tmp;
	int amount_tmp;
	cout << "Enter product name: ";
	name_tmp = read_string();
	cout << "Enter product price: ";
	price_tmp = read_double();
	int flag = 0;
	for (int i = 0; i < N; i++)
	{
		if ((store[i].get_price() == price_tmp) && (store[i].get_name() == name_tmp))
		{
			flag = 1;
			amount_tmp = store[i].get_amount();
			store[i].set_amount(amount_tmp + 1);
		}
	}
	if (flag == 0)
	{
		init_storage_1(store_add, name_tmp, price_tmp);
		vector <Storage> store_tmp(N + 1);
		for (int i = 0; i < N; i++)
		{
			store_tmp[i] = store[i];
		}
		store_tmp[N] = store_add;
		store.clear();
		store.resize(N + 1);
		N++;
		for (int i = 0; i < N; i++)
		{
			store[i] = store_tmp[i];
		}

	}

}

void erase_by_position(vector <Storage>& store, int& N)
{
	int position=0;
	while ((position == 0) || (position>N))
	{
		cout << "Enter the position of product: ";
		position = read_int();
	}
	vector <Storage> store_tmp(N-1);
	int k=0;
	for (int i = 0; i < N; i++)
	{
		if (i + 1 != position)
		{
			store_tmp[k] = store[i];
			k++;
		}
			
	}
	store.clear();
	store.resize(N - 1);
	N--;
	for (int i = 0; i < N; i++)
	{
		store[i] = store_tmp[i];
	}

}

/*


void add_new_end(vector <Storage>& store, int& N, Storage store_tmp)
{
	store.insert(store.end(), store_tmp);
}


void erase_by_position(vector <Storage>& store, int& N)
{
	//cout << "Which product would you like to delete?" << endl;
	int number = 0;
	while ((number == 0) || (number > N))
	{
		cout << "Which product would you like to delete?" << endl;
		number = read_int();
	}
	//store.erase(store.begin()+number-1);
	N--;
}
*/
int main()
{
	string s;
	int N = 0, last_menu_num = 11;
	int number_menu = 0, flagfile, number, count_before = 0;
	int flag_new_row_storage = 0;
	double double_number;
	Storage store;
	vector <Storage> store_v(1);
	vector <Storage> store_tmp(1);
#pragma region file
	ifstream file;
	file.open("lab.txt");
	if (!file) flagfile = 0;
	else
		flagfile = 1;
	if (flagfile == 1)
	{
		cout << "The data recorded during the previous run of the program" << endl;
		while (!file.eof())
		{
			getline(file, s);
			store_v[N].set_name(s);
			getline(file, s);
			double_number = stof(s);
			store_v[N].set_price(double_number);
			getline(file, s);
			number = stoi(s);
			store_v[N].set_amount(number);
			getline(file, s);
			number = stoi(s);
			store_v[N].set_num_s(number);
			getline(file, s);
			number = stoi(s);
			store_v[N].set_date_day(number);
			getline(file, s);
			number = stoi(s);
			store_v[N].set_date_month(number);
			getline(file, s);
			number = stoi(s);
			store_v[N].set_date_year(number);
			N++;
			for (int i = 0; i < N; i++)
			{
				store_tmp[i] = store_v[i];
			}
			store_v.clear();
			store_v.resize(N+1);
			for (int i = 0; i < N; i++)
			{
				store_v[i] = store_tmp[i];
			}
			store_tmp.clear();
			store_tmp.resize(N + 1); 
		}
		for (int i = 0; i < N; i++)
		{
			print(store_v, i);
			cout << endl;
		}
		count_before = N;
	};
	file.close();
#pragma endregion file
#pragma region menu
	while (number_menu != last_menu_num + 1)
	{
		cout << "Menu" << endl;
		cout << "___________________________________________________" << endl;
		cout << "Add new product...................................1" << endl;
		cout << "Print all products................................2" << endl;
		cout << "Find by section...................................3" << endl;
		cout << "Find product by date..............................4" << endl;
		cout << "Find expired product by date......................5" << endl;
		cout << "Sort by price.....................................6" << endl;
		cout << "Sort by amount....................................7" << endl;
		cout << "Add new element to the beginning..................8" << endl;
		cout << "Add new element to the end........................9" << endl;
		cout << "Erase product by it's position...................10" << endl;
		cout << "End the program..................................11" << endl;
		number_menu = 0;
		while (number_menu < 1 || number_menu>last_menu_num)
		{
			cout << "Enter number from 1 to 11 " << endl;
			number_menu = read_int();
		}
		switch (number_menu)
		{
		case 1:
		{
			init_storage_2(store_v, N);
			break;
		}
		case 2:
		{
			for (int i = 0; i < N; i++)
			{
				print(store_v, i);
				cout << endl;
			}
			break;
		}
		case 3:
		{
			find_by_section(store_v, N);
			break;
		}
		case 4:
		{
			find_by_date(store_v, N);
			break;
		}
		case 5:
		{
			find_expired_by_date(store_v, N);
			break;
		}
		case 6:
		{
			sort_by_price(store_v, N);
			break;
		}
		case 7:
		{
			sort_by_amount(store_v, N);
			break;
		}
		case 8:
		{
			add_to_begin(store_v, N);
			break;
		}
		case 9:
		{
			add_to_end(store_v, N);
			break;
		}
		case 10:
		{
			for (int i = 0; i < N; i++)
			{
				cout << "Product number " << i+1 << endl;
				print(store_v, i);
				cout << endl;
			}
			erase_by_position(store_v, N);
			break;
		}
		case 11:
		{
			if ((flagfile == 0) && (N != 0))
			{
				ofstream fileOut;
				fileOut.open("lab.txt", ios::out);
				fileOut.close();
				count_before = 0;
			}
			remove("lab.txt");
			if (N != 0)
			{
				
				flag_new_row_storage = 0;
				ofstream fileOut;
				fileOut.open("lab.txt", ios::app);
				for (int i = 0; i < N; i++)
				{
					if (flag_new_row_storage == 1)	fileOut << '\n';
					fileOut << store_v[i].get_name();
					fileOut << '\n';

					s = to_string(store_v[i].get_price());
					fileOut << s;
					fileOut << '\n';

					s = to_string(store_v[i].get_amount());
					fileOut << s;
					fileOut << '\n';

					s = to_string(store_v[i].get_num_s());
					fileOut << s;
					fileOut << '\n';

					s = to_string(store_v[i].get_date_day());
					fileOut << s;
					fileOut << '\n';

					s = to_string(store_v[i].get_date_month());
					fileOut << s;
					fileOut << '\n';

					s = to_string(store_v[i].get_date_year());
					fileOut << s;
					if (flag_new_row_storage == 0)
						flag_new_row_storage = 1;
				}
				fileOut.close();
			}
			number_menu = last_menu_num + 1;
			break;
		}
		}
	}
#pragma endregion menu
	return 0;
}