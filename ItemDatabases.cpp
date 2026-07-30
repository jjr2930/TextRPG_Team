#include "ItemDatabases.h"
#include <unordered_map>


ItemDatabase::ItemDatabase()
{
    Item item;

    std::unordered_map<Item> allItems;

	// 무기 아이템
    item.itemID = 0;
    item.name = "신성한 지팡이";
	item.value = 150;
	item.itemType = 0; // 무기 타입
    allItems[item.itemID] = item;

    item.itemID = 1;
    item.name = "화염 지팡이";
	item.value = 150;
	item.itemType = 0; // 무기 타입
    allItems[item.itemID] = item;

    item.itemID = 2;
    item.name = "빙하 지팡이";
	item.value = 150;
	item.itemType = 0; // 무기 타
    allItems[item.itemID] = item;

    item.itemID = 3;
    item.name = "일곱 신의 양손 검";
	item.value = 200;
    item.itemType = 0; // 무기 타입
    allItems[item.itemID] = item;

    item.itemID = 4;
    item.name = "양손 도끼";
    item.value = 200;
    item.itemType = 0; // 무기 타입
    allItems[item.itemID] = item;

    item.itemID = 5;
    item.name = "팔라딘의 방패와 검";
	item.value = 300;
    item.itemType = 0; // 무기 타입
    allItems[item.itemID] = item;

    item.itemID = 6;
    item.name = "신성한 활";
	item.value = 200;
    item.itemType = 0; // 무기 타입
    allItems[item.itemID] = item;

    item.itemID = 7;
    item.name = "명사수의 석궁";
	item.value = 250;
    item.itemType = 0; // 무기 타입
    allItems[item.itemID] = item;

    item.itemID = 8;
    item.name = "아킬레우스의 투창";
    item.value = 250;
    item.itemType = 0; // 무기 타입
    allItems[item.itemID] = item;


	// 회복 포션
    item.itemID = 9;
    item.name = "스태미나 물약";
    item.healAmount = 50;
    item.value = 50;
    item.itemType = 1; // 회복 포션 타입
    allItems[item.itemID] = item;

    item.itemID = 10;
    item.name = "체력 물약";
    item.healAmount = 50;
    item.value = 50;
    item.itemType = 1; // 회복 포션 타입
    allItems[item.itemID] = item;

    item.itemID = 11;
    item.name = "경험치 물약";
	item.healAmount = 50;
    item.value = 50;
    item.itemType = 1; // 회복 포션 타입
    allItems[item.itemID] = item;

    item.itemID = 12;
    item.name = "마나 물약";
	item.healAmount = 30;
    item.value = 50;
    item.itemType = 1; // 회복 포션 타입
    allItems[item.itemID] = item;

    item = Item{};

	// 버프 포션
    item.itemID = 13;
    item.name = "공격력 물약";
	item.buffAmount = 10;    
    item.value = 150;
    item.itemType = 2; // 버프 포션 타입
    allItems[item.itemID] = item;

    item.itemID = 14;
    item.name = "방어력 물약";
	item.buffAmount = 10;
    item.value = 250;
    item.itemType = 2; // 버프 포션 타입
    allItems[item.itemID] = item;



    item = Item{};
    
	// 기타 아이템

    item.itemID = 100;
    item.name = "슬라임 액체";
    item.value = 1;

    allItems[item.itemID] = item;

    loadedItems = allItems;
}
