#include <iostream>
#include <locale.h>
#include <windows.h>
#include <conio.h>
using namespace std;

enum Direction {
    Up = 72,    Up1 = -106,     Up2 = -26,      Up3 = 119,      Up4 = 87,
    Left = 75,  Left1 = -108,   Left2 = -28,    Left3 = 65,     Left4 = 97,
    Right = 77, Right1 = -126,  Right2 = -94,   Right3 = 68,    Right4 = 100, 
    Down = 80,  Down1 = -101,   Down2 = -21,    Down3 = 83,     Down4 = 115, 
    Enter = 13, esc = 27,       space = 32,     tab = 9
};
HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
const int SIZE_MAIN_MENU = 4;
string main_menu[SIZE_MAIN_MENU] = {
    "Новая игра",
    "Управление",
    "Участники проекта", 
    " Доступ к мини-играм"
};
const int SIZE_MENU_CHARACTERS = 5;
string menu_characters[SIZE_MENU_CHARACTERS] = {
    "Рыцарь",
    "Знахарь (чумной доктор)",
    "Фермер",
    "Охотник", 
    "Рудокоп (Гном)"
};
const int SIZE_MAP = 10;
int game_map[SIZE_MAP][SIZE_MAP] = {
    {0, 1, 2, 3, 4, 5, 6, 7, 8, 9},
    {10, 11, 12, 13, 14, 15, 16, 17, 18, 19},
    {20, 21, 22, 23, 24, 25, 26, 27, 28, 29},
    {30, 31, 32, 33, 34, 35, 36, 37, 38, 39},
    {40, 41, 42, 43, 44, 45, 46, 47, 48, 49},
    {50, 51, 52, 53, 54, 55, 56, 57, 58, 59},
    {60, 61, 62, 63, 64, 65, 66, 67, 68, 69},
    {70, 71, 72, 73, 74, 75, 76, 77, 78, 79},
    {80, 81, 82, 83, 84, 85, 86, 87, 88, 89},
    {90, 91, 92, 93, 94, 95, 96, 97, 98, 99}
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
void mini_games();
void act0_1();

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
    case 3: mini_games();
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
    int character = 0;
    character = menu(menu_characters, SIZE_MENU_CHARACTERS);
    start_game(character);
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
    cout << "\t\t\tКсения       - основной сюжет игры" << endl;
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
    case Up:
    case Up1:
    case Up2:
    case Up3:
    case Up4:    return 1; break;
    case Down:
    case Down1:
    case Down2:
    case Down3:
    case Down4:  return 3; break;
    case Right:
    case Right1:
    case Right2:
    case Right3:
    case Right4: return 2; break;
    case Left:
    case Left1:
    case Left2:
    case Left3:
    case Left4:  return 4; break;
    case space: return 5; break;
    case tab:   return 6; break;
    case Enter: return 7; break;
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
    case 0: cout << "рыцаря.\n";   break;
    case 1: cout << "знахаря.\n";        break;
    case 2: cout << "фермера.\n";         break;
    case 3: cout << "охотника.\n";  break;
    case 4: cout << "рудокопа.\n"; break;
    }
    cout << "\n\tНачните движение....\n";
    do
    {
        switch (run())
        {
        case 1: act0_1(character);                break;
        case 2: cout << "\tПовернули направо.\n";         break;
        case 3: cout << "\tИдем назад.\n";                break;
        case 4: cout << "\tПовернули налево.\n";          break;
        case 5: cout << "\tПрыгнули.\n";                  break;
        case 6: cout << "\tПоменяли предмет в руках.\n";  break;
        case 7: cout << "\tВыполнили действие.\n";        break;
        }
    } while (esc);
}

void mini_games()
{
    cout << "В разработке";
     if(_getch()) menu(main_menu, SIZE_MAIN_MENU);
}

void act0_1(int character)
{
    system("cls");
    cout << "\n\n\n\t\t\tИтак, первый шаг сделан, вокруг новый мир полный удивительных приключений!\n";
    cout << "\t\t\"Вперед\" - сказал я себе и сделал новый шаг.\n";
    do
    {
        switch (run())
        {
        case 1: cout << "\n\t\"Рубикон пройден!\" - сказал незнакомый голос.\n";                break;
        case 2: cout << "\tОпомнись! Коня потеряешь!.\n";         break;
        case 3: cout << "Назад?!";                break;
        case 4: cout << "\tНалево - сказку говорит.\n";          break;
        case 5: cout << "\tПрыгнули.\n";                  break;
        case 6: cout << "\tПоменяли предмет в руках.\n";  break;
        case 7: cout << "\tВыполнили действие.\n";        break;
        }
    } while (esc);
}
