#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include "Character.h"


enum class ItemType {
	Weapon,
	Potion,
	UpgradeCore,
	Miscellaneous
};

enum class ItemWeapon {
	Staff,
	SwordnShield,
	TwoHand,
	Daggers,
	Bow
};
enum class ItemEffect {
	None,
	RestoreHealth,
	AttackBuff,
	DefenseBuff,
	IncreaseEXP,
	RestoreMana
};

enum class ItemUpgrade {
	UpgradeAttack,
	UpgradeDefense,
	UpgradeMaxHP,
	UpgradeMaxMP
};

class Item {
public:
	std::string name;
	int itemID;
	int value; //가격

	ItemType itemType;
	ItemEffect itemEffect;
	ItemWeapon itemWeapon;
	ItemUpgrade itemUpgrade;

	int effectAmount;
	int upgradeAmount;
	int upgradeLevel=0;

	//무기
	int weaponAttack;
	int weaponDefense;
	int weaponMaxMP;
	int weaponMaxHP;

	void UsePotion(const Item& item, Character& character);
	void WieldWeapon(const Item& item, Item& playerWeapon);
	void UpgradeWeapon(const Item& item, Item& playerWeapon);	
};

