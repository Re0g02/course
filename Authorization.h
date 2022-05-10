#pragma once
#include<vector>
#include<iostream>
#include<conio.h>
#include<string>
#include<fstream>
#include"Common.h"
#include<vector>

using std::string;

string Hasher(string, string);

int Login(string& ,vector<user>);

int isLogin(vector<user>, string);

bool isLoggedIn(string, string, int&,vector<user>);

int reg_account(vector<user>&);

void addUser(string, string,vector<user>&,bool);

string enterString(string, bool);

bool isLoginLetter(char);