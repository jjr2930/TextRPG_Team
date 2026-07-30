#include "Item.h"
#include <iostream>
#include <vector>
#include <string>
#include "Inventory.h"
#include "Character.h"

void Item::useHealingPotion (int itemID, int useQuantity, std::vector<InventoryItem> mItems) {
	GetCurrentHP() += healAmount * useQuantity;
    }
void Item::useBuffPotion(int itemID, int useQuantity, std::vector<InventoryItem> mItems) {

}
	
//void Item::wieldWeapon(int itemID, std::vector<InventoryItem> mItems) {
//	;
//
//    }
