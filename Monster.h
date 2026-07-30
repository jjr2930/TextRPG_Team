#pragma once
#include <string>


#include "Battle.h"
#include "Item.h"
class Item;

class Monster : public Battle {
protected:
	std::string name;
	int hp;
	int power;
	int dropExp;
	Item* item;
	int gold;

public:
	Monster(std::string name, int minHp, int maxHp, int minPower, int maxPower, int dropExp, Item* item, int price, int level);
	int GetHp();
	int GetPower();
	int GetDropExp();
	std::string GetName();
	Item GetItem();
	int RandomGold();

	virtual void SetHp(int hp);
	virtual void SetPower(int power);

	virtual int RandomHp(int min, int max, int level);
	virtual int RandomPower(int min, int max, int level);

};