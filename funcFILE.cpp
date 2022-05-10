#include"funcFile.h"

//Создание файла с аккаунтами
void create_UsersFile() {
	vector<user> add;
	ofstream file(users);
	file.close();
	addUser("admin", "admin", add, true);
	write_user_file(add);
};

//Создание файла с товарами
void create_productsFile() {
	ofstream file(products);
	file.close();
};

//Если нет файла с аккаунтами или товарами:
void isFirstTime() {
	ifstream fin1, fin2;
	fin1.open(users);
	fin2.open(products);;
	if (!fin1) {
		cout << "Внимание система не обнаружила файл: " << users << endl;
		create_UsersFile();
		cout << "Файл " << users << " был создан по умолчанию." << endl<<endl;
		cout << "Для возможности дальнейшей работы был создан аккаунт:" << endl;
		cout << "Логин: admin" << endl << "Пароль: admin" << endl;
		system("pause");
	}
	if (!fin2) {
		cout << "Внимание система не обнаружила файл: " << products << endl;
		create_productsFile();
		cout << "Файл " << products << " был создан по умолчанию." << endl;
		system("pause");
	}
	fin1.close();
	fin2.close();
}

//Преобразовывает bool в string
string BoolToStr(bool num) {
	return num ? "1" : "0";
}

//Преобразовывает int в string;
string intToStr(int num) {
	stringstream strS;
	strS << num;
	return strS.str();
}

//Преобразовывает строку в информацию о акккаунте
user strToUser(string str) {
	stringstream strS(str);
	user temp;
	string substr;
	getline(strS, substr, '\t');
	temp.login = substr;
	getline(strS, substr, '\t');
	temp.password = substr;
	getline(strS, substr, '\t');
	temp.salt = substr;
	getline(strS, substr, '\t');
	temp.role = stoi(substr);
	getline(strS, substr, '\t');
	temp.access = stoi(substr);
	return temp;
}


//Преобразовывает информацию о акккаунте в строку
string userToStr(user Us) {
	return Us.login + '\t' + Us.password + '\t' + Us.salt + '\t' + BoolToStr(Us.role) + '\t' + BoolToStr(Us.access) + '\n';
}

//Преобразовывает строку в информацию о товаре
product strToProduct(string str) {
	stringstream strS(str);
	product temp;
	string substr;
	getline(strS, substr, '\t');
	temp.name = substr;
	getline(strS, substr, '\t');
	temp.amount = stoi(substr);
	getline(strS, substr, '\t');
	temp.unit_price = stoi(substr);
	getline(strS, substr, '\t');
	temp.date = substr;
	getline(strS, substr, '\t');
	temp.employee_name = substr;
	return temp;
}

//Преобразовывает информацию о товаре в строку
string productToStr(product Pr){
	return Pr.name + '\t' + intToStr(Pr.amount) + '\t' + intToStr(Pr.unit_price)+'\t'+Pr.date+'\t'+Pr.employee_name+'\n';
}

//Запись аккаунтов в файл
void write_user_file(vector<user>&usersData) {
		ofstream DATA(users);
		DATA.close();
		DATA.open(users, ios_base::app);
		for (int i = 0; i < usersData.size(); i++) 
			DATA << userToStr(usersData[i]);;
		DATA.close();	
}

//Чтение аккаунтов из файла
void read_user_file(vector<user>& usersData) {
	ifstream DATA(users, ios_base::in);	
	string is;
	while (getline(DATA, is)) {
		usersData.push_back(strToUser(is));
	}
	DATA.close();
};

//Запись товаров в файл
void write_product_file(vector<product>&productsData) {
	ofstream DATA(products);
	DATA.close();
	DATA.open(products, ios_base::app);
	for (int i = 0; i < productsData.size(); i++)
		DATA << productToStr(productsData[i]);;
	DATA.close();
}

//Чтение товаров из файла
void read_product_file(vector <product>& productsData) {
	ifstream DATA(products, ios_base::in);
	string is;
	while (getline(DATA, is)) {
		productsData.push_back(strToProduct(is));
	}
	DATA.close();
}