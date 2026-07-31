#include "Tools.h"

int GetIntegerInRange(int minValue, int maxValue) {
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

int GetRandomValue(int minValue, int maxValue) {
    static std::mt19937 randomEngine(std::random_device{}());
    std::uniform_int_distribution<int> distribution(minValue, maxValue);

    return distribution(randomEngine);
}


inline void WaitForKey()
{
    std::cout << std::endl << "계속하려면 아무 키나 누르세요...\n";
    (void)_getch();
}