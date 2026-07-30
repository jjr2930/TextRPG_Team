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

enum class ItemWeapon
{
	Staff,
	SwordnShield,
	TwoHand,
	Bow,
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
	ItemWeapon itemWeapon;

	int effectAmount;

	//무기
	int weaponAttack; 
	int weaponDefense;
	int weaponMaxMP;
	int weaponMaxHP;

	void UsePotion(const Item& item, Character& character);
	void UseWeapon(const Item& item, Character& character);

	
};

