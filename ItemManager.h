#pragma once
#include "Item.h"


class ItemManager {
public:
	Item playerWeapon; // 플레이어가 장착한 무기

	void EquipWeapon(const Item& item);
};d
