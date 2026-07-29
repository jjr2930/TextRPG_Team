#include <iostream>
#include <string>
#include <cstdlib>
#include "Boss.h"
#include "Character.h"

Boss::Boss()
	: Monster("오지게 강한 마왕", 40, 60, 10, 20, 100, "마검", 1, 10) {}

Boss::~Boss() {}

void Boss::Attack(Character* Character)
{
	int damage = power - Character->GetDefense();

	if (damage < 0)
		damage = 1;


	std::cout << "마왕에 성스러운 마검을 휘둘렀다.\n";
	std::cout << damage << " 데미지 공격!\n";
}