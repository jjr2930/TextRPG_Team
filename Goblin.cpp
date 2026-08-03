#include <iostream>

#include "Goblin.h"

Goblin::Goblin(Item* item, int level) : Monster("Goblin", 10, 40, 2, 18, 40, item, 16, level) {};

// 공격 메서드 - 3:2 비율로 해서 공격이 실행함 
void Goblin::Attack() {
	int num = random.GetRandomValue(0, 4);
	switch (num) {
	case 0:
	case 1:
	case 2:
		NomalAttack();
		break;
	case 3:
	case 4:
		ComboAttack();
		break;
	}
	std::cin.get();
}

void Goblin::TakeDamage(int damage) {
	currentHp -= damage;
	std::cout << damage << "만큼 " << name << "이 당했습니다.\n";
	if (currentHp <= 0)
		std::cout << name << "죽었습니다.\n";
	std::cin.get();
}

void Goblin::NomalAttack() {
	std::cout << name << "이 공격하였습니다. (" << power << ")\n";
	target->TakeDamage(power);
}

//  연속 공격의 공격 횟수 또한 랜덤으로 실행
void Goblin::ComboAttack() {
	std::cout << name << "이 연속 공격을 합니다!!\n";
	int totalPower = 0;
	int comboPower = random.GetRandomValue(1, 4);
	int randomNum = random.GetRandomValue(2, 6);
	for (int i = 1; i < randomNum; ++i) {
		std::cout << i << "번째 공격합니다. (" << comboPower << ")\n";
		target->TakeDamage(comboPower);
		totalPower += comboPower;
	}
	std::cout << "총 공격을 " << totalPower << "하였습니다.\n";
}