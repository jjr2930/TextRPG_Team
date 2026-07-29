#include "Item.h"
#include <iostream>
#include <vector>
#include <string>

void Item::useitem(int itemID, int useQTY) {
	if (itemID >= 0 && itemID <= 7)
	{
		std::cout << "Wielded " << useQTY << " " << name << std::endl;
	}
    else if (itemID > 7 && itemID <12 && QTY > 0)
    {
        QTY -= useQTY;
        std::cout << "Used " << useQTY << " " << name << ". Remaining quantity: " << QTY << std::endl;
    }
}

void sellItem(int itemID, int sellQTY, std::vector<Item>& allItems) {
	if (itemID >= 0 && itemID < allItems.size()) {
		Item& item = allItems[itemID];
		if (item.QTY >= sellQTY) {
			item.QTY -= sellQTY;
			std::cout << "Sold " << sellQTY << " " << item.name << ". Remaining quantity: " << item.QTY << std::endl;
		}
		else {
			std::cout << "Not enough quantity to sell. Current quantity: " << item.QTY << std::endl;
		}
	}
	else {
		std::cout << "Invalid item ID." << std::endl;
	}
}
	
std::vector<Item> LoadItems()
{
    Item item;

    std::vector<Item> allItems;

    item.itemID = 0;
    item.name = "Staff of Divine";//신성한 지팡이
    allItems.push_back(item);

    item.itemID = 1;
    item.name = "Staff of Inferno";//화염 지팡이
    allItems.push_back(item);

    item.itemID = 2;
    item.name = "Staff of Glaciers";//빙하 지팡이
    allItems.push_back(item);

    item.itemID = 3;
    item.name = "Undying Cleaver";//양손 검
    allItems.push_back(item);

    item.itemID = 4;
	item.name = "Blood Thirster";//양손 도끼, 출혈 효과
    allItems.push_back(item);

    item.itemID = 5;
    item.name = "Sword and Shield of Divinity";//방패와 검, 추가 방어력
    allItems.push_back(item);

    item.itemID = 6;
	item.name = "Blessed Bow of Divines";// 신성한 활
    allItems.push_back(item);

    item.itemID = 7;
    item.name = "Seven God's Crossbow";//석궁
    allItems.push_back(item);

    item.itemID = 8;
    item.name = "";//
    allItems.push_back(item);

    item.itemID = 9;
    item.name = "";//
    allItems.push_back(item);

    item.itemID = 10;
    item.name = "";//
    allItems.push_back(item);

    item.itemID = 11;
    item.name = "";//
    allItems.push_back(item);

    item.itemID = 12;
    item.name = "";//
    allItems.push_back(item);

    item.itemID = 13;
    item.name = "";//
    allItems.push_back(item);
    return allItems;
}