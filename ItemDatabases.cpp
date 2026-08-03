#include "ItemDatabases.h"
#include <unordered_map>
#include <string>
#include "Item.h"


const Item& ItemDatabase::GetItem(int itemID) {
    return allItems[itemID];
}

ItemDatabase::ItemDatabase()
{
    Item item;

    // 무기 아이템
    item.itemID = 0;
    item.name = "신성한 지팡이";
    item.value = 150;
    item.itemType = ItemType::Weapon;
    item.itemWeapon = ItemWeapon::Staff;
    item.weaponAttack = 35;
    item.weaponDefense = 5;
    item.weaponMaxMP = 30;
    allItems[item.itemID] = item;

    item.itemID = 1;
    item.name = "화염 지팡이";
    item.value = 150;
    item.itemType = ItemType::Weapon;
    item.itemWeapon = ItemWeapon::Staff;
    item.weaponAttack = 35;
    item.weaponDefense = 10;
    item.weaponMaxMP = 30;
    allItems[item.itemID] = item;

    item.itemID = 2;
    item.name = "빙하 지팡이";
    item.value = 150;
    item.itemType = ItemType::Weapon;
    item.itemWeapon = ItemWeapon::Staff;
    item.weaponAttack = 35;
    item.weaponDefense = 5;
    item.weaponMaxMP = 30;
    allItems[item.itemID] = item;

    item.itemID = 3;
    item.name = "일곱 신의 양손 검";
    item.value = 200;
    item.itemType = ItemType::Weapon;
    item.itemWeapon = ItemWeapon::TwoHand;
    item.weaponAttack = 30;
    item.weaponDefense = 20;
    item.weaponMaxHP = 30;
    allItems[item.itemID] = item;

    item.itemID = 4;
    item.name = "양손 도끼";
    item.value = 200;
    item.itemType = ItemType::Weapon;
    item.itemWeapon = ItemWeapon::TwoHand;
    item.weaponAttack = 30;
    item.weaponDefense = 20;
    item.weaponMaxHP = 35;
    allItems[item.itemID] = item;

    item.itemID = 5;
    item.name = "팔라딘의 방패와 검";
    item.value = 300;
    item.itemType = ItemType::Weapon;
    item.itemWeapon = ItemWeapon::SwordnShield;
    item.weaponAttack = 15;
    item.weaponDefense = 30;
    item.weaponMaxHP = 40;
    allItems[item.itemID] = item;

    item.itemID = 6;
    item.name = "신성한 활";
    item.value = 200;
    item.itemType = ItemType::Weapon;
    item.itemWeapon = ItemWeapon::Bow;
    item.weaponAttack = 30;
    item.weaponDefense = 15;
    allItems[item.itemID] = item;

    item.itemID = 7;
    item.name = "명사수의 석궁";
    item.value = 250;
    item.itemType = ItemType::Weapon;
    item.itemWeapon = ItemWeapon::Bow;
    item.weaponAttack = 30;
    item.weaponDefense = 15;
    allItems[item.itemID] = item;

    item.itemID = 8;
    item.name = "아킬레우스의 투창";
    item.value = 250;
    item.itemType = ItemType::Weapon;
    item.itemWeapon = ItemWeapon::Bow;
    item.weaponAttack = 30;
    item.weaponDefense = 15;
    allItems[item.itemID] = item;

    item.itemID = 9;
    item.name = "배신자의 단검";
    item.value = 250;
    item.itemType = ItemType::Weapon;
    item.itemWeapon = ItemWeapon::Daggers;
    item.weaponAttack = 40;
    item.weaponDefense = 5;
    allItems[item.itemID] = item;

    item.itemID = 10;
    item.name = "살인마의 쌍검";
    item.value = 250;
    item.itemType = ItemType::Weapon;
    item.itemWeapon = ItemWeapon::Daggers;
    item.weaponAttack = 40;
    item.weaponDefense = 5;
    allItems[item.itemID] = item;

    item.itemID = 11;
    item.name = "추적자의 단검";
    item.value = 250;
    item.itemType = ItemType::Weapon;
    item.itemWeapon = ItemWeapon::Daggers;
    item.weaponAttack = 40;
    item.weaponDefense = 5;
    allItems[item.itemID] = item;

    item = Item{};

    // 회복 포션
    item.itemID = 10;
    item.name = "체력 물약";
    item.value = 50;
    item.itemType = ItemType::Potion;
    item.itemEffect = ItemEffect::RestoreHealth;
    item.effectAmount = 50;
    allItems[item.itemID] = item;

    item.itemID = 11;
    item.name = "경험치 물약";
    item.value = 50;
    item.itemType = ItemType::Potion;
    item.itemEffect = ItemEffect::IncreaseEXP;
    item.effectAmount = 50;
    allItems[item.itemID] = item;

    item.itemID = 12;
    item.name = "마나 물약";
    item.value = 50;
    item.itemType = ItemType::Potion;
    item.itemEffect = ItemEffect::RestoreMana;
    item.effectAmount = 50;
    allItems[item.itemID] = item;

    item = Item{};

    // 버프 포션
    item.itemID = 13;
    item.name = "공격력 물약";
    item.value = 150;
    item.itemType = ItemType::Potion;
    item.itemEffect = ItemEffect::AttackBuff;
    item.effectAmount = 10;
    allItems[item.itemID] = item;

    item.itemID = 14;
    item.name = "방어력 물약";
    item.value = 150;
    item.itemType = ItemType::Potion;
    item.itemEffect = ItemEffect::DefenseBuff;
    item.effectAmount = 10;
    allItems[item.itemID] = item;

    item = Item{};
    //각성 원소
    item.itemID = 50;
    item.name = "각성 원소(공격력)";
    item.value = 300;
    item.itemType = ItemType::UpgradeCore;
    item.itemUpgrade = ItemUpgrade::UpgradeAttack;
    item.upgradeAmount = 20;
    allItems[item.itemID] = item;

    item.itemID = 51;
    item.name = "각성 원소(방어력)";
    item.value = 300;
    item.itemType = ItemType::UpgradeCore;
    item.itemUpgrade = ItemUpgrade::UpgradeDefense;
    item.upgradeAmount = 20;
    allItems[item.itemID] = item;

    item.itemID = 52;
    item.name = "각성 원소(최대 체력)";
    item.value = 300;
    item.itemType = ItemType::UpgradeCore;
    item.itemUpgrade = ItemUpgrade::UpgradeMaxHP;
    item.upgradeAmount = 30;
    allItems[item.itemID] = item;

    item.itemID = 53;
    item.name = "각성 원소(최대 마나)";
    item.value = 300;
    item.itemType = ItemType::UpgradeCore;
    item.itemUpgrade = ItemUpgrade::UpgradeMaxMP;
    item.upgradeAmount = 30;
    allItems[item.itemID] = item;

    // 기타 아이템

    item.itemID = 100;
    item.name = "슬라임 액체";
    item.value = 20;
    item.itemType = ItemType::Miscellaneous;
    allItems[item.itemID] = item;

    item.itemID = 101;
    item.name = "슬라임 눈물";
    item.value = 30;
    item.itemType = ItemType::Miscellaneous;
    allItems[item.itemID] = item;

    item.itemID = 102;
    item.name = "슬라임 분비물";
    item.value = 40;
    item.itemType = ItemType::Miscellaneous;
    allItems[item.itemID] = item;
}