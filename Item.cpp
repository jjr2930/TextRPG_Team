#include "Item.h"
#include <iostream>
#include "Inventory.h"
#include "Character.h"


//Item playerWeapon


//포션 사용
void Item::UsePotion(const Item& item, Character& character){
    switch (item.itemEffect)
    {
    case ItemEffect::RestoreHealth: {
        int currentHP = character.GetCurrentHP();
        currentHP += item.effectAmount;
        character.SetCurrentHP(currentHP);
        break;
    }
    case ItemEffect::AttackBuff: {
        int currentAttack = character.GetAdditionalAttack();
        currentAttack += item.effectAmount;
        character.SetAdditionalAttack(currentAttack);
        break;
    }
    case ItemEffect::DefenseBuff: {
        int currentDefense = character.GetAdditionalDefense();
        currentDefense += item.effectAmount;
        character.SetAdditionalDefense(currentDefense);
        break;
    }
    case ItemEffect::RestoreMana: {
        int currentMana = character.GetCurrentMP();
        currentMana += item.effectAmount;
        character.SetCurrentMP(currentMana);
        break;
    }
    }
}
void Item::UseWeapon(const Item& item, Character& character) {
    if (item.itemType != ItemType::Weapon) {
        return;
    }
    character.SetEquippedWeapon(
        item.itemID,
        item.weaponAttack,
        item.weaponDefense,
        item.weaponMaxHP,
        item.weaponMaxMP
    );
}
//무기 각성
void Item::UpgradeWeapon(const Item& item) {
    switch (item.itemUpgrade)
    {
    case ItemUpgrade::UpgradeAttack: {
        int weaponAttack = GetWeaponAttack();
        weaponAttack += item.upgradeAmount;
        SetAdditionalWeaponAttack(weaponAttack);
        upgradeLevel++;
        break;
    }
    case ItemUpgrade::UpgradeDefense: {
        int weaponDefense = GetWeaponDefense();
        weaponDefense += item.upgradeAmount;
        SetAdditionalWeaponDefense(weaponDefense);
        upgradeLevel++;
        break;
    }
    case ItemUpgrade::UpgradeMaxHP: {
        int weaponMaxHP = GetWeaponMaxHP();
        weaponMaxHP += item.upgradeAmount;
        SetAdditionalWeaponMaxHP(weaponMaxHP);
        upgradeLevel++;
        break;
    }
    case ItemUpgrade::UpgradeMaxMP: {
        int weaponMaxMP = GetWeaponMaxMP();
        weaponMaxMP += item.upgradeAmount;
        SetAdditionalWeaponMaxMP(weaponMaxMP);
        upgradeLevel++;
        break;
    }
    }
}
//무기 장착 Getter/Setter
int Item::GetWeaponAttack() const {
    return weaponAttack;
}
int Item::GetWeaponDefense() const {
	return weaponDefense;
}
int Item::GetWeaponMaxMP() const {
	return weaponMaxMP;
}
int Item::GetWeaponMaxHP() const {
	return weaponMaxHP;
}

//무기 각성 Getter/Setter
int Item::GetAdditionalWeaponAttack() const {
	return additionalWeaponAttack;
}
int Item::GetAdditionalWeaponDefense() const {
	return additionalWeaponDefense;
}
int Item::GetAdditionalWeaponMaxMP() const {
	return additionalWeaponMaxMP;
}
int Item::GetAdditionalWeaponMaxHP() const {
	return additionalWeaponMaxHP;
}
void Item::SetAdditionalWeaponAttack(int additionalWeaponAttack) {
    this->additionalWeaponAttack = additionalWeaponAttack;
}
void Item::SetAdditionalWeaponDefense(int additionalWeaponDefense) {
    this->additionalWeaponDefense = additionalWeaponDefense;
}
void Item::SetAdditionalWeaponMaxMP(int additionalWeaponMaxMP) {
    this->additionalWeaponMaxMP = additionalWeaponMaxMP;
}
void Item::SetAdditionalWeaponMaxHP(int additionalWeaponMaxHP) {
    this->additionalWeaponMaxHP = additionalWeaponMaxHP;
}
//합계 무기 Getter/Setter
int Item::GetTotalWeaponAttack() const {
	return GetWeaponAttack() + GetAdditionalWeaponAttack();
}
int Item::GetTotalWeaponDefense() const {
	return GetWeaponDefense() + GetAdditionalWeaponDefense();
}
int Item::GetTotalWeaponMaxMP() const {
	return GetWeaponMaxMP() + GetAdditionalWeaponMaxMP();
}
int Item::GetTotalWeaponMaxHP() const {
	return GetWeaponMaxHP() + GetAdditionalWeaponMaxHP();
}
