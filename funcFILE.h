#pragma once
#include"Authorization.h"
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<sstream>
#include"Common.h"

using namespace std;

const string users = "users_File.txt";
const string products = "products_File.txt";

user strToUser(string);
string userToStr(user);
product strToProduct(string);
string productToStr(product);
void create_UsersFile();
void create_productsFile();
void isFirstTime();
void read_user_file(vector<user>&);
void read_product_file(vector<product>&);
void write_user_file(vector<user>&);
void write_product_file(vector<product>&);
string BoolToStr(bool);