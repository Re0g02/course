#pragma once
#include <windows.h> 
#include<iostream>
#include<string>
#include<conio.h>
#include<ctime>

#ifdef max
#undef max
#endif

using namespace std;

struct user
{
	string login;
	string password;
	string salt;
	bool role;
	bool access;
};

struct product {
	string name;
	int amount;
	int unit_price;
	string date;
	string employee_name;
};

const string empty_string = "";
const string backspace_attribute = "\b \b";
const string users_file = "UserData.txt";
const string database_file = "Database.txt";
const char password_star = '*';
const unsigned int max_string_length = 32;
const unsigned int max_name_length = 128;
const unsigned int max_salary_length = 10;

void сlearRow();
string enterDate();
int enterInt();
int getCurrentDays();

