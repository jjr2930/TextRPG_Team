#include <iostream>

#include "skeleton.h"

Skeleton::Skeleton(Item* item, int level) : Monster("Skeleton", 15, 40, 5, 20, 45, item, 20, level) {};

void Skeleton::Attack() {
	int num = random.GetRandomValue(0, 2);
	switch (num) {
	case 0:
	case 1:
		ComboAttack();
		break;
	case 2:
		NomalAttack();
		break;
	}
}

void Skeleton::TakeDamage(int damage) {
	currentHp -= damage;
	std::cout << damage << "만큼 " << name << "이 당했습니다.\n";
	if (currentHp <= 0)
		std::cout << name << "죽었습니다.\n";
	std::cin.get();
}

void Skeleton::NomalAttack() {
	std::cout << name << "이 화살로 공격하였습니다. (" << power << ")\n";
	target->TakeDamage(power);
}

void Skeleton::ComboAttack() {
	std::cout << name << "이 연속 공격을 합니다!!\n";
	int totalPower = 0;
	int comboPower = power / 2;
	int randomNum = random.GetRandomValue(2, 4);
	for (int i = 1; i < randomNum; ++i) {
		std::cout << i << "번째 공격합니다. (" << comboPower << ")\n";
		target->TakeDamage(comboPower);
		totalPower += comboPower;
	}
	std::cout << "총 공격을 " << totalPower << "하였습니다.\n";
}