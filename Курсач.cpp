#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include"MENU.h"
#include"funcFILE.h"
#include"userFunc.h"
#include"Common.h"
#include"Authorization.h"

using namespace std;

//Главная функция
int main() {
	system("chcp 1251 > 0");
    system("color 0");
	string login;
	int answer;
	vector<user> usersData;
	vector<product> productsData;
    isFirstTime();
	read_user_file(usersData);
	read_product_file(productsData);
	while (true) {
		switch (Start_work()) {
		case 1:
			while (true) {
				answer = Login(login, usersData);
				if (answer == 3) continue;
				else if (answer == 2) break;
				else {
					work(login, answer,usersData,productsData);
					break;
				}
			}
			break;
		case 2:while (true) {
			answer = reg_account(usersData);
			if (answer == 1) continue;
			else break;
		}
			  break;
		case 3: write_user_file(usersData);
			write_product_file(productsData);
			cout << "Работа завершена.";
			return 0;
			break;
		}
	}
	return 0;
}