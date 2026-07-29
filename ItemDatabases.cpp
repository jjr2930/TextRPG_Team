#include "ItemDatabases.h"


ItemDatabase::ItemDatabase()
{
    Item item;

    std::vector<Item> allItems;

    item.itemID = 0;
    item.name = "신성한 지팡이";
    allItems.push_back(item);

    item.itemID = 1;
    item.name = "화염 지팡이";
    allItems.push_back(item);

    item.itemID = 2;
    item.name = "빙하 지팡이";
    allItems.push_back(item);

    item.itemID = 3;
    item.name = "양손 검";
    allItems.push_back(item);

    item.itemID = 4;
    item.name = "양손 도끼";
    allItems.push_back(item);

    item.itemID = 5;
    item.name = "신성한 방패와 검";
    allItems.push_back(item);

    item.itemID = 6;
    item.name = "신성한 활";
    allItems.push_back(item);

    item.itemID = 7;
    item.name = "명사수의 석궁";
    allItems.push_back(item);

    item.itemID = 8;
    item.name = "아킬레우스의 투창";
    item.healAmount = 50;
    allItems.push_back(item);

    item.itemID = 9;
    item.name = "";
    item.healAmount = 50;
    allItems.push_back(item);

    item.itemID = 10;
    item.name = "체력 물약";
    item.healAmount = 50;
    allItems.push_back(item);

    item.itemID = 11;
    item.name = "체력 물약";
	item.healAmount = 50;
    allItems.push_back(item);

    item.itemID = 9;
    item.name = "마나 물약";
	item.healAmount = 30;
    allItems.push_back(item);

    item.itemID = 10;
    item.name = "공격력 물약";
	item.buffAmount = 10;   
    allItems.push_back(item);

    item.itemID = 11;
    item.name = "방어력 물약";
	item.buffAmount = 10;
    allItems.push_back(item);

    item.itemID = 12;
    item.name = "회복 물약";
	item.healAmount = 50;
    allItems.push_back(item);

    item.itemID = 13;
    item.name = "마나 물약";
	item.healAmount = 30;
    allItems.push_back(item);

    item.itemID = 100;
    item.name = "슬라임 액체";
    item.value = 1;
    item.QTY = 1;
    allItems.push_back(item);

    loadedItems = allItems;
}
