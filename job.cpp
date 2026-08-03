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

const std::vector<Skill>&
Warrior::GetSkills() const
{
    static const std::vector<Skill> skills = {
        Skill("강철 베기",   3, 20, 15, 150),
        Skill("방패 강타",   5, 12, 25, 190),
        Skill("불굴의 일격", 7, 8,  35, 250)
    };

    return skills;
}

Mage::Mage()
    : Job("마법사") {
}

const std::vector<Skill>&
Mage::GetSkills() const
{
    static const std::vector<Skill> skills = {
        Skill("화염구",    3, 20, 25, 170),
        Skill("낙뢰",      5, 12, 40, 210),
        Skill("마력 폭발", 7, 8,  60, 280)
    };

    return skills;
}

Thief::Thief()
    : Job("도적") {
}

const std::vector<Skill>&
Thief::GetSkills() const
{
    static const std::vector<Skill> skills = {
        Skill("급소 찌르기", 3, 20, 20, 160),
        Skill("그림자 습격", 5, 12, 30, 210),
        Skill("암살",        7, 8,  45, 280)
    };

    return skills;
}

Archer::Archer()
    : Job("궁수") {
}

const std::vector<Skill>&
Archer::GetSkills() const
{
    static const std::vector<Skill> skills = {
        Skill("관통 사격", 3, 20, 20, 160),
        Skill("집중 사격", 5, 12, 35, 210),
        Skill("매의 눈",   7, 8,  45, 260)
    };

    return skills;
}


const Job* Job::SelectJob()
{
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

            std::cout
                << "숫자를 입력해주세요.\n";

            continue;
        }

        const JobType selectedJob =
            static_cast<JobType>(selection);

        switch (selectedJob) {
        case JobType::Warrior:
            return &warrior;

        case JobType::Mage:
            return &mage;

        case JobType::Thief:
            return &thief;

        case JobType::Archer:
            return &archer;

        default:
            std::cout
                << "1부터 4까지의 숫자를 입력해주세요.\n";
            break;
        }
    }
}
