#pragma once
#include <string>

class Monster {
protected:
	std::string name;
	int hp;
	int power;
	int dropExp;
	std::string dropItemName;
	int dropItemPrice;

public:
	Monster(std::string name, int hp, int power, int dropExp, std::string dropItemName, int dropItemPrice)
		: name(name), hp(hp), power(power), dropExp(dropExp), dropItemName(dropItemName), dropItemPrice(dropItemPrice) {
	}
	int GetHp();
	int GetPower();
	int GetDropExp();
	std::string GetName();
	std::string GetDropItemName();
	int GetDropItemPrice();

	virtual void Attack() = 0;
	virtual void TackDamage(int tackDamage) = 0;

};