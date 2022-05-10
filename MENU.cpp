#include"MENU.h"

//Создаёт меню
int create_menu(vector<string> options,string info)
{
    int counter = 1, chosen_option = counter;

    while (true)
    {
        system("cls");

        if(!(info=="")) cout << info << endl;

        for (size_t i = 0; i < options.size(); ++i)
        {
            if ((i + 1) == counter) std::cout << "> " << options[i] << std::endl;
            else                    std::cout << options[i] << std::endl;
        }

        char pressed = _getch();

        if ((pressed == 72) && counter != 1)
            counter--;
        if ((pressed == 80) && counter != (options.size()))
            counter++;

        if (pressed == '\r' || pressed == '\n') {
            chosen_option = counter;
            system("cls");
            return chosen_option;
        }
    }
}
