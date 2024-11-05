#include "Color.h"
#include <windows.h> 

void setColor(unsigned short text) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, text);
}