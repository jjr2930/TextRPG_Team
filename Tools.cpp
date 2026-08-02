#include "Tools.h"

int Tools::GetIntegerInRange(int minValue, int maxValue) {
    while (true) {
        std::string input;
        std::getline(std::cin >> std::ws, input);

        std::stringstream inputStream(input);

        int value;
        char remainingCharacter;

        bool isInteger =
            inputStream >> value &&
            !(inputStream >> remainingCharacter);

        bool isInRange =
            value >= minValue &&
            value <= maxValue;

        if (isInteger && isInRange)
            return value;

        std::cout << "잘못된 입력입니다. 다시 입력해 주세요.\n";
    }
}

void Tools::WaitForKey()
{
    std::cout << std::endl << "계속하려면 아무 키나 누르세요...\n";
    (void)_getch();
}
