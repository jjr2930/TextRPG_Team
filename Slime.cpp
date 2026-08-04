#include <iostream>

#include "Slime.h"



Slime::Slime(ItemDatabase* itemDB, int level) : Monster("Slime", 20, 30, 5, 10, 30, itemDB ,15, level) {};

Item Slime::GetItem() {
	int randomNum = random.GetRandomValue(100, 102);
	return itemDB->GetItem(randomNum);
}

// 공격 메서드 - 랜덤으로 공격이 실행됨
void Slime::Attack() {
	int num = random.GetRandomValue(0, 2);
	switch (num) {
	case 0:
		NomalAttack();
		break;
	case 1:
		ComboAttack();
		break;
	case 2:
		PowerfulAttack();
		break;
	}
	std::cin.get();
}

void Slime::TakeDamage(int damage) {
	currentHp -= damage;
	std::cout << damage << "만큼 " << name << "이 당했습니다.\n";
	if (currentHp <= 0) 
		std::cout << name << "죽었습니다.\n";
	std::cin.get();
}

void Slime::NomalAttack() {
	std::cout<< name << "이 공격하였습니다. (" << power << ")\n";
	target->TakeDamage(power);
}

void Slime::ComboAttack() {
	std::cout << name << "이 연속 공격을 합니다!\n";
	int totalPower = 0;
	for (int i = 1; i <= 3; ++i) {
		std::cout << i << " 번째 공격합니다. (" << power / 2 << ")\n";
		target->TakeDamage(power/2);
		totalPower += power / 2;
	}
	std::cout << "총 공격을 " << totalPower << "하였습니다.\n";
}

void Slime::PowerfulAttack() {
	std::cout << name << "이 강한 공격을 합니다!! ( ";
	int power = this->power * 2;
	std::cout << power << " )\n";

	target->TakeDamage(power);
}