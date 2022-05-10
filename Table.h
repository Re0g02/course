#include<iostream>

#include<vector>
#include <iomanip>
#include"Common.h"

#pragma once

using namespace std;

const string tProductUp = "| № |Название товара                   | Кол-во   | Цена     | Дата     | Фио сотрудника                   |";
const string tUserUp = "| № | Логин                             | Пароль                            |Дост.|Роль |";

void create_userTable(vector<user>);

void create_productTable(vector<product>);
