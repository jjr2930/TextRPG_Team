#pragma once

#include <string>
#include <vector>

class Item
{
public:
	std::string name;
	int itemID;
	int value; //가격
	int itemType; // 아이템 타입 (0: 무기, 1: 회복 포션, 2: 버프 포션, 3: 기타)

	//포션
	int healAmount; // HP/MP 회복량
	int buffAmount; // 버프량

	//무기
	int weaponAttack; 
	int weaponDefense;
	
	



	void useHealingPotion(int itemID, int useQuantity);
	void wieldWeapon(int itemID)
};
enum class ItemType
{
	Weapon,
	Potion,
	Buff,
	Miscellaneous
};
class 
