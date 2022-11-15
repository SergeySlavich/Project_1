#include <iostream>
#include <locale.h>
#include <windows.h>
#include <conio.h>
using namespace std;

enum Direction {
    Up = 72, Up1 = -106, Up2 = -26, Up3 = 119, Up4 = 87,
    Left = 75, Left1 = -108, Left2 = -28, Left3 = 65, Left4 = 97,
    Right = 77, Right1 = -126, Right2 = -94, Right3 = 68, Right4 = 100,
    Down = 80, Down1 = -101, Down2 = -21, Down3 = 83, Down4 = 115,
    Enter = 13, esc = 27, space = 32, tab = 9
};
HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
const int SIZE_MAIN_MENU = 3;
string main_menu[SIZE_MAIN_MENU] = {
    "Новая игра",
    "Управление",
    "Участники проекта"
};
const int SIZE_MENU_CHARACTERS = 4;
string menu_characters[SIZE_MENU_CHARACTERS] = {
    "Крестьянин",
    "Рыцарь",
    "Купец",
    "Ремесленник"
};

void SetCursor(int x, int y)
{
    COORD myCoords = { x, y };
    SetConsoleCursorPosition(hStdOut, myCoords);
}

int menu(string arr[], const int SIZE);
void new_game();
void control();
void staff();
void start_game(int character);
int run();

void main()
{
    setlocale(LC_ALL, "Russian");
    int poz = 0;
    poz = menu(main_menu, SIZE_MAIN_MENU);
    switch (poz)
    {
    case 0: new_game();
    case 1: control();
    case 2: staff();
    }
}

int menu(string menu[], const int SIZE)
{
    system("cls");
    int poz = 0;
    do {
        for (int i = 0; i < SIZE; i++)
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
        switch (_getch())
        {
        case Up: if (--poz < 0) poz = SIZE - 1; break;
        case Down: if (++poz > SIZE - 1) poz = 0; break;
        case Enter: return(poz);
        }
    } while (esc);
}

void new_game()
{
    system("cls");
    setlocale(LC_ALL, "Russian");
    int select = 0;
    select = menu(menu_characters, SIZE_MENU_CHARACTERS);
    start_game(select);
}

void control()
{
    system("cls");
    cout << "\n\n\n\t\tУправление персонажем осуществляется\n\t\t с помощью клавиш управления курсором\n\t\t и кнопок \'W\', \'A\', \'S\', \'D\',\n\t\t клавиш табуляции, пробела и \'Enter\':\n";
    cout << "\t\tКнопка \"Вверх\"   -   вперед\n";
    cout << "\t\tКнопка \"Вниз\"    -   назад\n";
    cout << "\t\tКнопка \"Вправо\"  -   вправо\n";
    cout << "\t\tКнопка \"Влево\"   -   влево\n";
    cout << "\t\tКнопка \"Пробел\"  -   прыжок\n";
    cout << "\t\tКнопка \"tab\"     -   смена оружия\n";
    cout << "\t\tКнопка \"Escape\"  -   выход в меню\n";
    if (_getch()) menu(main_menu, SIZE_MAIN_MENU);
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
    if (_getch()) menu(main_menu, SIZE_MAIN_MENU);
}

int run()
{
    switch (_getch())
    {
    case Up:    return 1; break;
    case Down:  return 3; break;
    case Right: return 2; break;
    case Left:  return 4; break;
    case space: return 5; break;
    case tab:   return 6; break;
    case Enter: return 7; break;
    case 'W': return 1; break;
    case 'S': return 3; break;
    case 'D': return 2; break;
    case 'A': return 4; break;
    case 'w': return 1; break;
    case 's': return 3; break;
    case 'd': return 2; break;
    case 'a': return 4; break;
    case 'ц': return 1; break;
    case 'ы': return 3; break;
    case 'в': return 2; break;
    case 'ф': return 4; break;
    case 'Ц': return 1; break;
    case 'Ы': return 3; break;
    case 'В': return 2; break;
    case 'Ф': return 4; break;



    }
}

void start_game(int character)
{
    system("cls");
    setlocale(LC_ALL, "Russian");
    cout << "\n\n\n\n\n\t\t\tТададам-тададаммммм...\n\n\n\t\t\t***ИГРА НАЧАЛАСЬ!***\n";
    cout << "\t\t В одной далекой-далекой галактике....\n\t\t\tОй, нет, это уже было.";
    cout << "\n\n\t\t\tДобро пожаловать в игру.\n Вы выбрали в качестве персонажа ";
    switch (character)
    {
    case 0: cout << "крестьянина.\n";   break;
    case 1: cout << "рыцаря.\n";        break;
    case 2: cout << "купца.\n";         break;
    case 3: cout << "ремесленника.\n";  break;
    }
    cout << "\nНачните движение....\n";
    do
    {
        switch (run())
        {
        case 1: cout << "Идем прямо.\n";                break;
        case 2: cout << "Повернули направо.\n";         break;
        case 3: cout << "Идем назад.\n";                break;
        case 4: cout << "Повернули налево.\n";          break;
        case 5: cout << "Прыгнули.\n";                  break;
        case 6: cout << "Поменяли предмет в руках.\n";  break;
        case 7: cout << "Выполнили действие.\n";        break;
        }
    } while (esc);
}
