#pragma once
#include <string>
#include <random>

class Monster {
protected:
	std::string name;
	int hp;
	int power;
	int dropExp;
	std::string dropItemName;
	int dropItemPrice;

public:
	Monster(std::string name, int minHp, int maxHp, int minPower, int maxPower, int dropExp, std::string dropItemName, int dropItemPrice, int level);
	int GetHp();
	int GetPower();
	int GetDropExp();
	std::string GetName();
	std::string GetDropItemName();
	int GetDropItemPrice();

	virtual void SetHp(int hp);
	virtual void SetPower(int power);

	virtual int RandomHp(int min, int max, int level);

};