#include"Authorization.h"

//Проверка на допустимые символы в пароле
bool isLoginLetter(char inp) {
	if ((inp >= '0' && inp <= '9') ||
		(inp >= 'A' && inp <= 'Z') ||
		(inp >= 'a' && inp <= 'z') ||
		inp == '_' || inp == '-') return true;
	return false;
}

//Хеширование пароля
string Hasher(string pas, string salt) {
	int hash_buf = 1, p_size = pas.size();
	string hash = empty_string;
	for (int i = 0; i < 4; i++)
		hash_buf += salt[i] / p_size;
	hash_buf /= p_size;
	for (int i = 0; i < p_size; i++)
		hash_buf += hash_buf / pas[i];
	for (int i = 0; i < 8; i++) {
		char add;
		if (i < 4)
			add = hash_buf + salt[i];
		else
			add = hash_buf + salt[i - 4] - p_size;
		if (add > 128) add /= p_size / 3;
		if (add < 33) add += p_size + 33;
		hash += add;
	}
	return hash;
}

// Авторизация
int  Login(string &login,vector<user> usersData) {
	string password;
	system("cls");
	cout << "Заполните поля ниже для использования системы (esc - отмена)\n";
	login = enterString("Логин",false);
	if (login == "") return 2;
	password = enterString("Пароль", true);
	if (password == "") return 2;
	int role;
	if (!(isLoggedIn(login, password, role,usersData))) {
		system("pause");
		return 3;
	}
	return role;
}

//Проверка на занятость логина
int isLogin(vector<user> usersData, string login) {
	for (int i = 0; i < usersData.size(); i++) {
		if (usersData[i].login == login) {
			return true;
		}
	}
	return false;
}

//Проверка пароля и доступа
bool isLoggedIn(string log, string pas, int& role,vector<user> usersData) {
	bool answer = false;
	for (int i = 0; i < usersData.size();i++) {
		if (usersData[i].login == log)
			if (usersData[i].password == Hasher(pas, usersData[i].salt)) {
				answer = true;
				if (!usersData[i].access) {
					cout << "Данная учётная запись не подтверждена. Обратитесь к администратору" << endl;
					return false;
				}
				else role = usersData[i].role;
				break;
			}
			else break;
	}
	if (!answer)
		cout << "Логин или пароль не совпадают\n";
	return answer;
}

//функция для ввода пароля и логина
string enterString(string title, bool is_password) {
	bool arrow = false;
	string str = empty_string;
	cout << title << ":\n";
	while (true) {
		char act = _getch();
		int ch = static_cast<int>(act);

		if (ch == 27) return empty_string;
		if (ch == 13) {
			if (str == empty_string) continue;
			cout << endl;
			return str;
		}

		if (arrow) {
			arrow = false;
			continue;
		}
		if (ch == -32) {
			arrow = true;
			continue;
		}

		if (ch == 8) {
			if (!str.length()) continue;
			str.resize(str.length() - 1);
			cout << backspace_attribute;
		}
		else {
			if (!isLoginLetter(act)) continue;
			if (str.length() >= max_string_length) {
				сlearRow();
				cout << "Размер этого поля не может превышать " << max_string_length << "! Нажмите любую клавишу для продолжения...";
				str = _getch();
				сlearRow();
				str = empty_string;
				continue;
			}
			str += act;
			if (is_password) cout << password_star;
			else cout << act;
		}
	}
	return str;
}

//Регистрация аккаунта
int reg_account(vector<user> &usersData) {
	system("cls");
	string login, password, repeat_password;
	cout << "Заполните поля ниже для регистрации (esc - отмена)\n";
	if (isLogin(usersData,login = enterString("Логин",false))) {
		cout << "Данный логин занят. Используйте другой\n";
		system("pause");
		return 1;
	}
	if (login == "") return 2;
	password = enterString("Пароль", true);
	if (password == "") return 2;
	repeat_password = enterString("Повторите пароль", true);
	if (repeat_password == "") return 2;
	if (password == repeat_password)
		addUser(login, password,usersData,false);
	else {
		cout << "Пароли не совпадают\n";
		system("pause");
		return 1;
	}
	cout << "Регистрация завершена. Дождитесь подтверждения учётной записи администратором\n";
	system("pause");
	return 2;
}

//Добавление пользователя
void addUser(string login, string password,vector<user>& usersData,bool role) {
	user user;
	string salt = "";
	srand(time(NULL));
	for (int i = 0; i < 4; i++) {
		char inp = rand() % 126 + 33;
		salt += inp;
	}
	user.login = login;
	user.password = Hasher(password, salt);
	user.salt = salt;
	user.role =  role;
	user.access = role;
	usersData.push_back(user);
}