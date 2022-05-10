#include"userFunc.h"

//Создание начального меню
int Start_work() {
	string info;
	vector<string> menu;
	info = "Система по учёту товаров на складе || Выберите действие:\n";
	menu.push_back("Войти в учётную запись.");
	menu.push_back("Зарегистрироваться.");
	menu.push_back("Выход из системы.");
	return create_menu(menu, info);
}

//Вывод товаров
void view_products(vector<product>products) {
	if(products.size()==0) cout<<"Список товаров пуст.\n";
	else create_productTable(products);
	system("pause");
}

//Поиск товаров
int search_product(vector<product>products) {
	vector<product> inTable;	
	vector<string> menu;
	string info;
	int inf;
	info = "Искать по:";
	menu.push_back("Названию");
	menu.push_back("Количеству");
	menu.push_back("Цене");	
	menu.push_back("Дате");
	menu.push_back("ФИО работника");
	menu.push_back("Выход");
	switch (create_menu(menu, info)) {
	case 1: cout << "Введите название продукта: ";
		getline(cin,info);
		for (int i = 0; i < products.size(); i++) if (products[i].name == info) inTable.push_back(products[i]);
		break;
	case 2:cout << "Введите количество товара: ";
		inf = enterInt();
		for (int i = 0; i < products.size(); i++) if (products[i].amount == inf) inTable.push_back(products[i]);
		break;
	case 3:cout << "Введите цену товара: ";
		inf=enterInt();
		for (int i = 0; i < products.size(); i++)if (products[i].unit_price == inf) inTable.push_back(products[i]);
		break;
	case 4: cout<<"Введите дату:";
		info = enterDate();
		for (int i = 0; i < products.size(); i++)if (products[i].date == info)inTable.push_back(products[i]);
	case 5:cout << "Введите ФИО работника: ";
		getline(cin,info);
		for (int i = 0; i < products.size(); i++)if (products[i].employee_name == info)inTable.push_back(products[i]);
		break;
	case 6: return 0;
	}
	system("cls");
	if (inTable.size() == 0)cout << "Найдено " << inTable.size() << " товаров.\n";
	else {
		cout << "Найдено " << inTable.size() << " товаров:\n";
		create_productTable(inTable);
	}
	system("pause");
	return 0;
}

//Сортировка товаров
int sort_product(vector<product>& products) {
	if (products.size() == 0) {
		cout << "Список товаров пуст.\n";
		system("pause");
		return 0;
	}
	int choice;
	product temp;
	string info,sr1,sr2;
	vector<string> menu;
	info = "Сортировать по";
	menu.push_back("Названию товара");
	menu.push_back("Количеству");
	menu.push_back("Цене");
	menu.push_back("ФИО работника");
	menu.push_back("Выход");
	choice = create_menu(menu, info);
	for (int i = 0; i < products.size(); i++) {
		for (int j = (products.size() - 1); j >= (i + 1); j--) {
			switch (choice)
			{
			case 1:if (products[j - 1].name.compare(products[j].name) == 1) {
					temp = products[j];
					products[j] = products[j - 1];
					products[j - 1] = temp;
				   }
				break;
			case 4:if (products[j - 1].employee_name.compare(products[j].employee_name) == 1) {
					temp = products[j];
					products[j] = products[j - 1];
					products[j - 1] = temp;
				   }
				break;
			case 2:if (products[j - 1].amount< products[j].amount) {
					temp = products[j];
					products[j] = products[j - 1];
					products[j - 1] = temp;
				   }
				break;
			case 3:if (products[j - 1].unit_price< products[j].unit_price) {
					temp = products[j];
					products[j] = products[j - 1];
					products[j - 1] = temp;
				   }
				break;
			case 5:return 0;
			}
		}
	}
	create_productTable(products);
	cout << "Товары успешно отсортированы." << endl;
	system("pause");
}

//Редактирование товаров
int edit_product(vector<product>& products) {
	int num;
	bool pr=true;
	string info,info1;
	vector<string>menu,menu1;
	if (products.size() == 0) {
		cout << "Список товаров пуст." << endl;
		system("pause");
		return 0;
	}
	else create_productTable(products);
	cout << endl<<"Введите порядковый номер товара, который хотите редактировать:"<<endl;
	while (true) {
		num=enterInt();
		if (num<0 || num>products.size()) cout << "Номер введён неверно, попробуйте ещё раз:" << endl;
		else {
			num--;
			break;
		}
	}
	system("cls");
	info = "Что будем редактировать?";
	menu.push_back("Название товара");
	menu.push_back("Количество товара");
	menu.push_back("Цену товара");
	menu.push_back("Дату");
	menu.push_back("ФИО работника");
	menu.push_back("Выход");
	info1 = "Редактирование прошло успешно.\nХотите продолжить?";
	menu1.push_back("Да");
	menu1.push_back("Нет");
	while(pr){
		switch (create_menu(menu,info))
		{
		case 1: cout << "Введите новое название товара:" << endl;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			getline(cin, products[num].name);
			break;
		case 2:cout << "Введите новое количество товара:" << endl;
			cin >> products[num].amount;
			break;
		case 3:cout << "Введите новую цену товара:" << endl;
			cin >> products[num].unit_price;
			break;
		case 4: cout << "Введите новую дату (дд.мм.гггг):" << endl;
			products[num].date=enterDate();
			break;
		case 5: cout << "Введите новое ФИО работника:" << endl;
			getline(cin, products[num].employee_name);
			break;
		case 6:return 0;
		}
		system("cls");
		if (create_menu(menu1, info1) == 2)pr = false;
	}
	return 0;
}

//Добавление товаров
void addProduct(vector<product>& products) {
	product add;
	cout << "Введите название товара:" << endl;
	getline(cin,add.name);
	cout << "Введите количество товара:" << endl;
	add.amount=enterInt();
	cout << "Введите цену товара:" << endl;
	add.unit_price=enterInt();
	cout << "Введите дату (дд.мм.гггг):" << endl;
	cin.ignore( numeric_limits<streamsize>::max(), '\n');
	add.date=enterDate();
	cout << "Введите ФИО сотрудника:" << endl;
	getline(cin,add.employee_name);
	products.push_back(add);
	system("cls");
	cout << "Товар успешно добавлен в список."<<endl;
	system("pause");
	system("cls");
}

//Удаление товаров
int delProduct(vector<product>& products) {
	int num;
	vector<product> buf;
	string info;
	vector<string> menu;
	if (products.size() == 0) {
		cout << "Список товаров пуст." << endl;
		system("pause");
		return 0;
	}
	else create_productTable(products);
	cout << "Введите порядковый номер товара:" << endl;
	while (true) {
		num = enterInt();
		if (num<1 || num>products.size()) cout << "Ошибка ввода,попробуйте ещё раз" << endl;
		else {
			num--;
			break;
		}
	}
	for (int i = 0; i < products.size(); i++) if (i != num) buf.push_back(products[i]);
	info = "Удалить товар " + products[num].name + " из списка?";
	menu.push_back("Да");
	menu.push_back("Нет");
	if (create_menu(menu, info) == 1) {
		products = buf;
		cout << "Товар успешно удалён из списка.";
	}
	else cout << "Товар не удалён из списка.";
	system("pause");
	return 0;
}

//Преобразует дату в дни
int DateInDays(string date) {
	
	return (date[0] - '0') * 10 + (date[1] - '0') +
		((date[3] - '0') * 10 + (date[4] - '0')) * 30 +
		((date[6] - '0') * 1000 + (date[7] - '0') * 100 +
		(date[8] - '0') * 10 + (date[9] - '0')) * 365;
}

//Индивидуальное задание
int indTask(vector<product>products) {
	vector<product> inTable;
	int mon,praice,j;
	product temp;
	cout << "Введите кол-во месяцев: " << endl;
	mon = enterInt();
	cout << "Введите цену:" << endl;
	praice = enterInt();
	for (int i = 0; i < products.size(); i++) if (getCurrentDays() - DateInDays(products[i].date) > (mon * 30) 
		                                          && products[i].unit_price > praice) inTable.push_back(products[i]);
	for (int i = 0; i < inTable.size(); i++) {
		for (int j = (inTable.size() - 1); j >= (i + 1); j--) {
			if (inTable[j - 1].name.compare(inTable[j].name) == 1) {
				temp = inTable[j];
				inTable[j] = inTable[j - 1];
				inTable[j - 1] = temp;
			}
		}
	}
	if (inTable.size() == 0) {
		cout << "Список товаров пуст.\n";
		system("pause");
		return 0;
	}
	create_productTable(inTable);
	system("pause");
}

//Вывод аккаунтов
void view_users(vector<user> users){
	if (users.size() == 0) cout << "Список аккаунтов пуст.\n";
	else create_userTable(users);
	system("pause");
}

//Редактирование аккаунтов
int edit_user(vector<user>& users ,string login){
	if (users.size() == 0) {
		cout << "Список аккаунтов пуст.\n";
		system("pause");
		return 0;
	}
	else create_userTable(users);
	bool pr = true;
	string info,info1,newLogin;
	vector<string> menu,menu1;
	vector<string> menuA,menuR;
	int num;
	cout << endl << "Введите порядковый номер аккаунта , который хотите редактировать:" << endl;
	while (true) {
		num = enterInt();
		if (num<0 || num>users.size()) cout << "Номер введён неверно, попробуйте ещё раз:" << endl;
		else if (users[--num].login == login) cout << "Нельзя редактировать свой аккаунт" << endl;
		else break;
	}
	system("cls");
	info = "Что будем редактировать?";
	info1 = "Редактирование прошло успешно.\nХотите продолжить?";
	menu.push_back("Логин");
	menu.push_back("Пароль");
	menu.push_back("Доступ");
	menu.push_back("Роль");
	menu.push_back("Выход");
	menu1.push_back("Да");
	menu1.push_back("Нет");
	menuA.push_back("Вкл.");
	menuA.push_back("Выкл.");
	menuR.push_back("Админ");
	menuR.push_back("Пользователь");
	while (pr) 
	{
		switch (create_menu(menu, info))
		{
		case 1:while (true) {
			if (isLogin(users, newLogin = enterString("Введите новый логин:", false))) {
				cout << "Данный логин занят. Используйте другой\n";
				system("pause");
			}
			else {
				users[num].login = newLogin;
				break;
			}
			}
			  break;
		case 2:users[num].password = Hasher(enterString("Введите новый пароль:", true),users[num].salt);
			   break;
		case 3: 
			if (create_menu(menuA, "Доступ:") == 1) users[num].access = 1;
			else users[num].access = 0;
			break;
		case 4:
			if (create_menu(menuR, "Роль:") == 1)users[num].role = 1;
			else users[num].role = 0;
			break;
		case 5: return 0;
		}
		system("cls");
		if (create_menu(menu1, info1) == 2)pr = false;
	}
	return 0;
}

//Удаление аккаунтов
int delUser(vector<user>& users,string login){
	int num;
	vector<user> buf;
	string info;
	vector<string> menu;
	if (users.size() == 0) {
		cout << "Список аккаунтов пуст." << endl;
		system("pause");
		return 0;
	}
	else create_userTable(users);
	cout << "Введите порядковый номер товара:" << endl;
	while (true) {
		num = enterInt();
		if (num<1 || num>users.size()) cout << "Ошибка ввода,попробуйте ещё раз" << endl;
		else if (users[--num].login == login) cout << "Нельзя удалить свой аккаунт." << endl;
		else break;
	}
	for (int i = 0; i < users.size(); i++) if (i != num) buf.push_back(users[i]);
	info = "Удалить аккаунт " + users[num].login + " из списка?";
	menu.push_back("Да");
	menu.push_back("Нет");
	if (create_menu(menu, info) == 1) {
		users = buf;
		cout << "Аккаунт успешно удалён из списка."<<endl;
	}
	else cout << "Аккаунт не удалён из списка."<<endl;
	system("pause");
	return 0;
}

//Создание меню администратора
int adminFunc(vector<user>& users,string login) {
	string info = "Админ-меню, выберите действие:";
	vector<string> menu;
    menu.push_back("Просмотреть все аккаунты");
	menu.push_back("Добавить аккаунт");
	menu.push_back("Редактировать аккаунт");
	menu.push_back("Удалить аккаунт");
	menu.push_back("Выход");
	while (true) {
		switch (create_menu(menu, info))
		{
		case 1:view_users(users);
			break;
		case 2:reg_account(users);
			break;
		case 3:edit_user(users,login);
			break;
		case 4:delUser(users,login);
			break;
		case 5:return 0;
		}
	}
}

//Создание пользовательского меню
int work(string login, int role, vector<user> &users, vector<product>&products) {
	string info;
	vector<string> menu;
	if (role)info = "Добро пожаловать Администратор! Выберите действие:\n";
	else info = "Добро пожаловать Пользователь! Выберите действие:\n";
	menu.push_back("Просмотр списка товаров на складе");
	menu.push_back("Редактировать список товаров");
	menu.push_back("Поставить товар на учёт");
	menu.push_back("Снять товар с учёта");
	menu.push_back("Поиск товара");
	menu.push_back("Сортировака товара");
	menu.push_back("Поиск просроченных товаров");
	if (role)menu.push_back("Функционал администратора");
	menu.push_back("Выйти из учётной записи");
	while (true) {
		switch (create_menu(menu, info))
		{
		case 1:
			view_products(products);
			break;
		case 2:edit_product(products);
			break;
		case 3:addProduct(products);
			break;
		case 4:delProduct(products);
			break;
		case 5:search_product(products);
			break;
		case 6:sort_product(products);
			break;
		case 7:indTask(products);
			break;
		case 8: if (role) adminFunc(users,login);
			  else return 0;
			break;
		case 9: return 0;
		}
	}
	return 0;
}