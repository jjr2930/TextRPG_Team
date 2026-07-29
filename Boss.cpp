#include <iostream>
#include <string>
#include <cstdlib>
#include "Boss.h"
#include "Character.h"

Boss::Boss(Item* item, int level)
	: Monster("오지게 강한 마왕", 40, 60, 10, 20, 100, item, 1000, level) {}

Boss::~Boss() {}

void Boss::Attack(Character* Character)
{
	int damage = power - Character->GetDefense();

	if (damage < 0)
		damage = 1;

	int newCharacterHP = Character->GetCurrentHP() - damage;
	if (newCharacterHP <= 0)
		newCharacterHP = 0;

	Character->SetCurrentHP(newCharacterHP);


	std::cout << "마왕에 성스러운 마검을 휘둘렀다.\n";
	std::cout << "플레이어에게 " << damage << " 데미지 공격!\n";
	std::cout << "플레이어의 현재 HP: " << Character->GetCurrentHP() << "\n";
	std::cin.get();

	if (Character->GetCurrentHP() <= 0) {
		std::cout << "===================================================\n";
		std::cout << "                  [ GAME OVER ]\n";
		std::cout << " 마왕에 공격에 플레이어가 쓰러졌습니다.\n";
		std::cout << "===================================================\n";

		std::cin.get();
		exit(0);
	}

	if (hp <= 0) {
		std::cout << "===================================================\n";
		std::cout << "                  [ GAME CLEAR ]\n";
		std::cout << " 마왕에 사라지고 어둠이 사라졌습니다.\n";
		std::cout << " 플레이어의 이름은 영원히 기억될 것 입니다.\n";
		std::cout << "===================================================\n";
		std::cout << "            - RPG GAME CLEAR & CREDITS -\n";
		std::cout << "                   팀장 - 주정열\n";
		std::cout << "                  매니저 - 천우진\n";
		std::cout << "                   팀원 - 김규정\n";
		std::cout << "                   팀원 - 황승용\n";
		std::cout << "                   팀원 - 조수현\n";
		std::cout << "                   팀원 - 장영민\n";
		std::cout << " ==================================================\n";

		std::cin.get();
		exit(0);
	}

}