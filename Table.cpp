#include"Table.h"

//Рисует границы таблицы товаров
void drawProductTable() {
	cout << '+';
	int i;
	for (i = 0; i < 3; i++) cout << '=';
	cout << '+';
	for (i = 0; i < 34; i++) cout << '=';
	cout << '+';
	for (i = 0; i < 10; i++) cout << '=';
	cout << '+';
	for (i = 0; i < 10; i++) cout << '=';
	cout << '+';
	for (i = 0; i < 10; i++) cout << '=';
	cout << '+';
	for (i = 0; i < 34; i++) cout << '=';
	cout << '+';
	cout << endl;
}

//Рисует границы таблицы аккаунтов
void drawUserTable() {
	cout << '+';
	for (int i = 0; i < 3; i++)cout << '=';
	cout << '+';
	for (int i = 0; i < 35; i++)cout << '=';
	cout << '+';
	for (int i = 0; i < 35; i++)cout << '=';
	cout << '+';
	for (int i = 0; i < 5; i++)cout << '=';
	cout << '+';
	for (int i = 0; i < 5; i++)cout << '=';
	cout << '+';
	cout << endl;
}

//Выводит информацию об аккаунте в таблиццу
void drawUserInfo(user info, int num) {
	cout << "|" << setw(3) << left << num
		<< "|" << setw(35) << info.login
		<< "|" << setw(36) << info.password
		<< "|" << setw(5) << info.access
		<< "|" << setw(5) << info.role << "|" << endl;
}

//Выводит информацию о товаре в таблиццу
void drawProductInfo(product info,int num) {
	cout << "|" << setw(3) << left << num
		 << "|" << setw(34) << info.name
		 << "|" << setw(10) << info.amount
		 << "|" << setw(10) << info.unit_price
		 << "|" << setw(10) << info.date
		 << "|" << setw(34) << info.employee_name <<"|" << endl;
}

//Подгоняет поля товара под размеры таблицы
vector<product> InpToOutpProduct(vector<product>inp) {
	vector<product> outp;
	for (int i = 0; i < inp.size(); i++) {
		outp.push_back(inp[i]);
		if (outp[i].name.size() > 34) {
			while (outp[i].name.size() > 31) outp[i].name.pop_back();
			outp[i].name += "...";
		}
		if (outp[i].employee_name.size() > 34) {
			while (outp[i].employee_name.size() > 31) outp[i].employee_name.pop_back();
			outp[i].employee_name += "...";
		}
	}
	return outp;
}

//Подгоняет поля аккаунта под размеры таблицы
vector<user> InpToOutpUser(vector<user>inp) {
	vector<user> outp;
	for (int i = 0; i < inp.size(); i++) {
		outp.push_back(inp[i]);
		if (outp[i].login.size() > 35) {
			while (outp[i].login.size() > 32) outp[i].login.pop_back();
			outp[i].login += "...";
		}
		if (outp[i].password.size() > 35) {
			while (outp[i].password.size() > 32) outp[i].password.pop_back();
			outp[i].password += "...";
		}
	}
	return outp;
}

//Создание таблиццы товаров
void create_productTable(vector<product>inp){
	vector<product>outp;
	outp = InpToOutpProduct(inp);
	drawProductTable();
	cout << tProductUp << endl;
	drawProductTable();
	for (int i = 0; i < outp.size(); i++) {
		drawProductInfo(outp[i], i + 1);
		if(i!=(outp.size()-1))drawProductTable();
	}
	drawProductTable();
}

//Создание таблиццы аккаунтов
void create_userTable(vector<user> inp){
	vector<user>outp;
	outp = InpToOutpUser(inp);
	drawUserTable();
	cout << tUserUp << endl;
	drawUserTable();
	for (int i = 0; i < outp.size(); i++) {
		drawUserInfo(outp[i], i + 1);
		if (i != (outp.size() - 1))drawUserTable();
	}
	drawUserTable();
}