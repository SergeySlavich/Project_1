#include <iostream>
#include <locale.h>
#include <windows.h>
#include <conio.h>
using namespace std;

enum Direction { Up = 72, Left = 75, Right = 77, Down = 80, Enter = 13, esc = 27, spase = 32 };
HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
const int SIZE_MENU = 3;
const int SIZE_MENU_CHARACTERS = 4;

void SetCursor(int x, int y)
{
    COORD myCoords = { x, y };
    SetConsoleCursorPosition(hStdOut, myCoords);
}

int menu();
void new_game();
void control();
void staff();
int menu_characters();
void start_game(int character);
int run();

void main()
{
    setlocale(LC_ALL, "Russian");
    int poz = 0;
    poz = menu();
    switch (poz)
    {
    case 0: new_game();
    case 1: control();
    case 2: staff();
    }
}

int menu()
{
    system("cls");
    char menu[SIZE_MENU][50] = {
        "Новая игра",
        "Управление",
        "Участники проекта"
    };
    int poz = 0, key;

    do {
        for (int i = 0; i < SIZE_MENU; i++)
        {
            SetCursor(10, 10 + i);

            if (i == poz)
            {
                SetCursor(8, 10 + i);
                cout << "# ";
            }
            else
            {
                SetCursor(8, 10 + i);
                cout << "  ";
            }
            cout << menu[i];
        }

        key = _getch();
        switch (key)
        {
        case Up: if (--poz < 0) poz = SIZE_MENU - 1; break;
        case Down: if (++poz > SIZE_MENU - 1) poz = 0; break;
        case Enter: return(poz);
        }
    } while (key != esc);
}

void new_game()
{
    system("cls");
    setlocale(LC_ALL, "Russian");
    int select = 0;
    select = menu_characters();
    start_game(select);
}

int menu_characters()
{
    char menu_characters[SIZE_MENU_CHARACTERS][50] = {
        "Крестьянин",
        "Рыцарь",
        "Купец",
        "Ремесленник"
    };
    int select = 0, key;

    do {
        for (int i = 0; i < SIZE_MENU_CHARACTERS; i++)
        {
            SetCursor(10, 10 + i);

            if (i == select)
            {
                SetCursor(8, 10 + i);
                cout << "# ";
            }
            else
            {
                SetCursor(8, 10 + i);
                cout << "  ";
            }
            cout << menu_characters[i];
        }

        key = _getch();
        switch (key)
        {
        case Up: if (--select < 0) select = SIZE_MENU_CHARACTERS - 1; break;
        case Down: if (++select > SIZE_MENU_CHARACTERS - 1) select = 0; break;
        case Enter: return(select);
        case esc: menu();
        }
    } while (key != esc);
}

void control()
{
    system("cls");
    cout << "Управление персонажем осуществляется с помощью клавиш управления курсором:\n";
    cout << "Кнопка \"Вверх\" - вперед\n";
    cout << "Кнопка \"Вниз\" - назад\n";
    cout << "Кнопка \"Вправо\" - вправо\n";
    cout << "Кнопка \"Влево\" - влево\n";
    if (_getch()) menu();
}

void staff()
{
    setlocale(LC_ALL, "Ru");
    system("cls");
    cout << "\n\n\n\n\n";
    cout << "\t\t\tПривет       " << endl;
    cout << "\t\t\tСергей       -       код игры (пока что)" << endl;
    cout << "\t\t\tХаос         " << endl;
    cout << "\t\t\tКсения       " << endl;
    cout << "\t\t\tЕлена        " << endl;
    cout << "\t\t\tКирилл       " << endl;
    cout << "\t\t\tИлья         " << endl;
    cout << "\t\t\tИгорь        " << endl;
    cout << "\t\t\tЮлия         " << endl;
    if (_getch()) menu();
}

int run()
{
    switch (_getch())
    {
    case Up: return 1; break;
    case Down: return 3; break;
    case Right: return 2; break;
    case Left: return 4; break;
    }
}

void start_game(int character)
{
    system("cls");
    setlocale(LC_ALL, "Russian");
    cout << "\n\n\n\n\n\t\t\tТададам-тададаммммм...\n\n\n\t\t\t***ИГРА НАЧАЛАСЬ!***\n";
    cout << "\n\n\t\t\tДобро пожаловать в игру.\n Вы выбрали в качестве персонажа ";
    switch (character)
    {
    case 0: cout << "крестьянина.\n"; break;
    case 1: cout << "рыцаря.\n"; break;
    case 2: cout << "купца.\n"; break;
    case 3: cout << "ремесленника.\n"; break;
    }
    cout << "\nНачните движение....\n";
    do
    {
        switch (run())
        {
        case 1: cout << "Идем прямо.\n"; break;
        case 2: cout << "Повернули направо.\n"; break;
        case 3: cout << "Идем назад.\n"; break;
        case 4: cout << "Повернули налево.\n"; break;
        }
    } while (esc);
    cout << "Вышли из цикла";
}