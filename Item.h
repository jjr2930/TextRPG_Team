#pragma once

#include <string>
#include <vector>

class Item
{
public:
	std::string name;
	int itemID;
	int value; //가격
	int quantity;// 수량

	int healAmount; // HP/MP 회복량
	int buffAmount; // 버프량
	
	
	void useitem(int itemID, int useQTY);
};
std::vector<Item> LoadItems();

