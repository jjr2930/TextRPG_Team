#include <iostream>

#include "Slime.h"



Slime::Slime(Item* item, int level) : Monster("Slime", 20, 30, 5, 10, 30, item, 20, level) {};

void Slime::Attack() {
	target->TakeDamage(power);
	std::cout << name << "이(가) 공격하였습니다. (" << power << "\n";
}

void Slime::TakeDamage(int damage) {
	hp -= damage;
	std::cout << damage << "만큼 " << name << "이(가) 당했습니다.\n";
	if (hp <= 0) 
		std::cout << name << "죽었습니다.\n";
}
