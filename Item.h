#pragma once

#include <string>

class Character;

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
private:
	int additionalWeaponAttack = 0;
	int additionalWeaponDefense = 0;
	int additionalWeaponMaxMP = 0;
	int additionalWeaponMaxHP = 0;

	int totalWeaponAttack;
	int totalWeaponDefense;
	int totalWeaponMaxMP;
	int totalWeaponMaxHP;

public:
	std::string name;
	int itemID=0;
	int value=0; //가격

	ItemType itemType;
	ItemEffect itemEffect;
	ItemWeapon itemWeapon;
	ItemUpgrade itemUpgrade;

	int effectAmount=0;
	int upgradeAmount=0;
	int upgradeLevel=0;
	
	//무기
	int weaponAttack=0;
	int weaponDefense=0;
	int weaponMaxMP=0;
	int weaponMaxHP=0;

	void UsePotion(const Item& item, Character& character);
	void UseWeapon(const Item& item, Character& character);
	void UpgradeWeapon(const Item& item);

	//무기 장착 시 공격력, 방어력, 최대마나, 최대체력 증가
	int GetWeaponAttack() const;
	int GetWeaponDefense() const;
	int GetWeaponMaxMP() const;
	int GetWeaponMaxHP() const;
	//무기 각성시 추가 공격력, 추가 방어력, 추가 최대마나, 추가 최대체력 증가
	int GetAdditionalWeaponAttack() const;
	int GetAdditionalWeaponDefense() const;
	int GetAdditionalWeaponMaxMP() const;
	int GetAdditionalWeaponMaxHP() const;

	void SetAdditionalWeaponAttack(int additionalWeaponAttack);
	void SetAdditionalWeaponDefense(int additionalWeaponDefense);
	void SetAdditionalWeaponMaxMP(int additionalWeaponMaxMP);
	void SetAdditionalWeaponMaxHP(int additionalWeaponMaxHP);
	//합계 무기 공격력, 방어력, 최대마나, 최대체력
	int GetTotalWeaponAttack() const;
	int GetTotalWeaponDefense() const;
	int GetTotalWeaponMaxMP() const;
	int GetTotalWeaponMaxHP() const;
};
