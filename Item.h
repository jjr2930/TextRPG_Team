#pragma once

#include <string>
#include <vector>

class Item
{
public:
	std::string name;
	int itemID;
	int value;
	int QTY;
	
	void useitem(int itemID, int useQTY);
};
std::vector<Item> LoadItems();

