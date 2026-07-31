#include <iostream>
#include <string>
#include "Boss.h"
#include "Character.h"

Boss::Boss(Item* item, int level)
	: Monster("오지게 강한 마왕", 40, 60, 10, 20, 100, item, 1000, level) {}

Boss::~Boss() {}

void Boss::Attack() {
	target->TakeDamage(power);
	std::cout << "마왕에 성스러운 마검을 휘둘렀다.\n" << std::endl;
	std::cin.get();
}

void Boss::TakeDamage(int damage) {

	/* int finalDamage = (int)damage;
		if (finalDamage < 0)
			finalDamage = 1;  

	hp = hp - finalDamage;
	if (hp <= 0)
		hp = 0;  */

	std::cout << "마왕이 " << damage << " 의 데미지를 입혔습니다.!\n" << std::endl;      

	if (hp <= 0) {                                      
		std::cout << "===================================================\n" << std::endl;
		std::cout << " 언젠간 어둠 속에서 다시 일어 날 것이다!!!\n";
		std::cout << "===================================================\n" << std::endl;

		std::cin.get();
	}
}