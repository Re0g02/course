#include"Common.h"

//Очищение строки
void сlearRow() {
	cout << "\r";
	for (int i = 0; i < 16; i++) cout << "      ";
	cout << "\r";
}

//Ввод даты с проверкой
string enterDate() {
	string line;
	int pr;
	while (true) {
		getline(cin, line);
		if (line.size() != 10) cout << "Неверный формат.\n";
		else {
			if (line[2] != '.' || line[5] != '.')cout << "Неверный формат.\n";
			else {
				pr = (line[0]-48) * 10 + (line[1]-48);
				if (pr > 31 || pr < 1) cout << "Неверный формат.\n";
				else {
					pr = (line[3]-48) * 10 + (line[4]-48);
					if (pr > 12 || pr < 1) cout << "Неверный формат.\n";
					else {
						pr = (line[6]-48) * 1000 + (line[7]-48) * 100 + (line[8]-48) * 10 + (line[9]-48);
						if (pr > 2022 || pr < 0)cout << "Неверный формат.\n";
						else return line;
					}
				}
			}
		}
	}
}

//Ввод числа с проверкой
int enterInt() {
	int inp;
	while (true) {
		cin >> inp;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Ошибка ввода, попробуйте ещё раз" << endl;
		}
		else  if (inp == INT_MAX || inp<1) cout << "Неверное значение числа, попробуйте ещё раз" << endl;
		else return inp;
	}
}

//Возвращает кол-во дней
int getCurrentDays()
{
	SYSTEMTIME tm;
	GetLocalTime(&tm);
	return tm.wDay +(tm.wMonth*30) + (tm.wYear*365);
}

