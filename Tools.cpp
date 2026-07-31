#include "Tools.h"
#include <random>


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
