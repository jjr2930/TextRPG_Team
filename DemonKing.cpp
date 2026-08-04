#include <iostream>
#include <string>
#include "DemonKing.h"
#include "Character.h"

DemonKing::DemonKing(ItemDatabase* itemDB, int level)
	: Monster(" 악마들의 정점 - 마왕 ", 100, 150, 20, 30, 100, itemDB, 500, level) {}

DemonKing::~DemonKing() {}

Item DemonKing::GetItem() {
	int randomNum = random.GetRandomValue(106, 108);
	return itemDB->GetItem(randomNum);
}

void DemonKing::Attack() {
	

	int currentPower = power;

	if (currentHp <= (maxHp / 2)) {
		currentPower = (power * 2) / 3;

		std::cout << " 마력으로 감싸진 성스러운 마검으로 공격했습니다. " << "(" << currentPower << ")" << "\n" << std::endl;
		std::cin.get();
	}
	else if (currentHp <= (maxHp / 5)) {
		currentPower = power * 2;

		std::cout << " 마왕에 모든 마력이 담긴 짙은 푸른색 성스러운 마검으로 공격했습니다. " << "(" << currentPower << ")" << "\n" << std::endl;
		std::cin.get();
	}
	else {
		std::cout << " 마왕에 성스러운 마검을 휘둘러 공격했습니다. " << "(" << currentPower << ")" << "\n" << std::endl;
		std::cin.get();
	}

	Monster::target->TakeDamage(power);
	
}

void DemonKing::TakeDamage(int damage) {
	currentHp -= damage;

	/* int finalDamage = (int)damage;
		if (finalDamage < 0)
			finalDamage = 1;  

	hp = hp - finalDamage;
	if (hp <= 0)
		hp = 0;  */

	if (currentHp <= (maxHp / 2) && currentHp > (maxHp / 5) && !isRage) {
		isRage == true;

		std::cout << "===================================================\n" << std::endl;
		std::cout << " 재밌어지는군. 좀 더 날 즐겁게 해다오!!" << name << "(이)여!!!!!~~~~~~\n" << std::endl;
		std::cout << " 마왕이 분노하여 공격력이 강해집니다!\n" << std::endl;
		std::cout << " 마왕에 검이 마력으로 감싸져 빛이나기 시작합니다.\n" << std::endl;
		std::cout << " [분노 모드]: 마왕에 공격력이 1.5배가 됩니다.\n" << std::endl;
		std::cout << "===================================================\n" << std::endl;
		std::cin.get();
	}

	if (currentHp <= (maxHp / 5) && !isAwaken) {
		isAwaken == true;

		std::cout << "===================================================\n" << std::endl;
		std::cout << " 날 여기까지 몰아부치는" << name << "는(은) 오랜만이군......\n" << std::endl;
		std::cout << " 여기까지 몰아부친 걸 후회하게 만들어주마!!!!!!!!!!!\n" << std::endl;
		std::cout << " 죽어라!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n" << std::endl;
		std::cout << " 모든 마력을 폭발시킨 마력이 마왕과 마검에 깃들어 마왕이 더욱 강해집니다.\n" << std::endl;
		std::cout << " [각성 모드}: 마왕에 공격력이 2배가 됩니다.\n" << std::endl;
		std::cin.get();
	}   

	if (currentHp <= 0) {                                      
		std::cout << "===================================================\n" << std::endl;
		std::cout << " 언젠간 어둠 속에서......난 다시 일어 날 것이다~~\n" << std::endl;
		std::cout << " 그때는.내가..널...\n" << std::endl;
		std::cout << "===================================================\n" << std::endl;
		std::cin.get();

		Item droppedItem = this->GetItem();
		std::cout << "===================================================\n" << std::endl;
		std::cout << " 악마들의 정점 - 마왕이 왕이 쓰러졌다!\n" << std::endl;
		std::cout << " [획득 아이템]: " << droppedItem.name << std::endl;
		std::cout << "===================================================\n" << std::endl;
		std::cin.get();
	}
}