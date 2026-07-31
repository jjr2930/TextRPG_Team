#include <iostream>
#include <limits>

#include "job.h"

Job::Job(const std::string& name)
    : name(name) {
}

const std::string& Job::GetName() const {
    return name;
}

Warrior::Warrior()
    : Job("전사") {
}

Mage::Mage()
    : Job("마법사") {
}

Thief::Thief()
    : Job("도적") {
}

Archer::Archer()
    : Job("궁수") {
}

const Job* Job::SelectJob() {
    static const Warrior warrior;
    static const Mage mage;
    static const Thief thief;
    static const Archer archer;

    while (true) {
        std::cout << "\n직업을 선택해주세요.\n";
        std::cout << "1. 전사\n";
        std::cout << "2. 마법사\n";
        std::cout << "3. 도적\n";
        std::cout << "4. 궁수\n";
        std::cout << "선택: ";

        int selection;

        if (!(std::cin >> selection)) {
            std::cin.clear();
            std::cin.ignore(
                std::numeric_limits<std::streamsize>::max(),
                '\n'
            );

            std::cout << "숫자를 입력해주세요.\n";
            continue;
        }

        switch (selection) {
        case 1:
            return &warrior;
        case 2:
            return &mage;
        case 3:
            return &thief;
        case 4:
            return &archer;
        default:
            std::cout << "1부터 4까지의 숫자를 입력해주세요.\n";
            break;
        }
    }
}
