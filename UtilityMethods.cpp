#include "UtilityMethods.h"
#include <iostream>
#include <conio.h>

void UtilityMethods::WaitForKey()
{
    std::cout << std::endl << "계속하려면 아무 키나 누르세요...\n";
    _getch();
}
