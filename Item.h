#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include "Character.h"


enum class ItemType
{
	Weapon,
	Potion,
	Miscellaneous
};

enum class ItemEffect
{
	None,
	RestoreHealth,
	AttackBuff,
	DefenseBuff,
	RestoreStamina,
	RestoreMana
};

class Item
{
public:
	std::string name;
	int itemID;
	int value; //가격

	ItemType itemType;
    ItemEffect itemEffect;

	int effectAmount;

	////무기
	//int weaponAttack; 
	//int weaponDefense;
	void useItem(const Item& item, Character& character);
	std::unordered_map<int, Item> allItems;
};

