#include <windows.h>
#include <iostream>
#include <string>
using namespace std;

//VALORILE SUNT STORATE IN COD HEXADECIMAL dar poti utiliza si valoare in BAZA 10 
//#define FOREGROUND_BLUEE     110000 ///interesant
//#define FOREGROUND_BLUEE     0x0900 ///white
//#define FOREGROUND_BLUEE     0x0800 // lini verticale
//define  FOREGROUND_BLUEE     0x0400 ///linie deasupra;\
//#define FOREGROUND_BLUEE     0x0700 ///linie deasupra;\
//0x0000
//prima cifra rep culoare text
//a doua background

//#define FOREGROUND_BLUEE     0x0007 ///white
//#define FOREGROUND_BLUEE     0x0008 ///gray
//#define FOREGROUND_BLUEE     0x0009 ///blue
//#define FOREGROUND_BLUEE     36864 ///white 2304
void SetConsoleColour(WORD* Attributes, DWORD Colour)
{
    CONSOLE_SCREEN_BUFFER_INFO Info;
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(hStdout, &Info);
    *Attributes = Info.wAttributes;
    SetConsoleTextAttribute(hStdout, Colour);
}

void ResetConsoleColour(WORD Attributes)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Attributes);
}

int main()
{
    WORD Attributes = 0;
    SetConsoleColour(&Attributes, FOREGROUND_RED);
    printf("Foreground change..\n");
    ResetConsoleColour(Attributes);

    printf("Normal attributes..\n");

    SetConsoleColour(&Attributes, BACKGROUND_INTENSITY | BACKGROUND_RED);
    printf("Background change..\n");
    ResetConsoleColour(Attributes);
    printf("Normal attributes..\n");


    SetConsoleColour(&Attributes, FOREGROUND_INTENSITY | FOREGROUND_RED);
    printf("Mixture");
    ResetConsoleColour(Attributes);
    printf(" of ");
    SetConsoleColour(&Attributes, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
    printf("both..\n");
    ResetConsoleColour(Attributes);


    SetConsoleColour(&Attributes, FOREGROUND_INTENSITY | FOREGROUND_BLUEE);
    printf("!!!!!!!! AICI SE MODIFICA !!!!!!!!!!!1");
    ResetConsoleColour(Attributes);
    printf(" of ");
    SetConsoleColour(&Attributes, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
    printf("all ");
    ResetConsoleColour(Attributes);
    SetConsoleColour(&Attributes, BACKGROUND_INTENSITY | BACKGROUND_GREEN);
    printf("three");
    ResetConsoleColour(Attributes);
    printf(" ");
    SetConsoleColour(&Attributes, BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_BLUE | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    printf("in a single line\n");
    ResetConsoleColour(Attributes);

    string n;
    cin >> n;
    SetConsoleColour(&Attributes, BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_BLUE | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    cout << n;
    ResetConsoleColour(Attributes);
}

