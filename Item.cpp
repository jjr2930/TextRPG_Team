#include "Item.h"
#include <iostream>
#include <vector>
#include <string>
#include "Inventory.h"
#include "Character.h"

//Item playerWeapon 필요


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
//무기 장착
void Item::WieldWeapon(const Item& item, Item& playerWeapon) {
    switch (item.itemWeapon)
    {
    case ItemWeapon::Staff: {
       
        playerWeapon.SetWeaponAttack(item.weaponAttack);
        playerWeapon.SetWeaponDefense(item.weaponDefense);
        playerWeapon.SetWeaponMaxMP(item.weaponMaxMP);
        break;
    }
    case ItemWeapon::SwordnShield: {
       
        playerWeapon.SetWeaponAttack(item.weaponAttack);
        playerWeapon.SetWeaponDefense(item.weaponDefense);
        playerWeapon.SetWeaponMaxHP(item.weaponMaxHP);
        break;
    }
    case ItemWeapon::TwoHand: {
        playerWeapon.SetWeaponAttack(item.weaponAttack);
        playerWeapon.SetWeaponDefense(item.weaponDefense);
        playerWeapon.SetWeaponMaxHP(item.weaponMaxHP);
        break;
    }
    case ItemWeapon::Bow: {
        playerWeapon.SetWeaponAttack(item.weaponAttack);
        playerWeapon.SetWeaponDefense(item.weaponDefense);
        playerWeapon.SetWeaponMaxMP(item.weaponMaxMP);
        break;
    }
    }
}
//무기 각성
void Item::UpgradeWeapon(const Item& item, Item& playerWeapon) {
    switch (item.itemUpgrade)
    {
    case ItemUpgrade::UpgradeAttack: {
        int weaponAttack = playerWeapon.weaponAttack;
        weaponAttack += item.upgradeAmount;
        playerWeapon.SetAdditionalWeaponAttack(weaponAttack);
        playerWeapon.upgradeLevel++;
        break;
    }
    case ItemUpgrade::UpgradeDefense: {
        int weaponDefense = playerWeapon.weaponDefense;
        weaponDefense += item.upgradeAmount;
        playerWeapon.SetAdditionalWeaponDefense(weaponDefense);
        playerWeapon.upgradeLevel++;
        break;
    }
    case ItemUpgrade::UpgradeMaxHP: {
        int weaponMaxHP = playerWeapon.weaponMaxHP;
        weaponMaxHP += item.upgradeAmount;
        playerWeapon.SetAdditionalWeaponMaxHP(weaponMaxHP);
        playerWeapon.upgradeLevel++;
        break;
    }
    case ItemUpgrade::UpgradeMaxMP: {
        int weaponMaxMP = playerWeapon.weaponMaxMP;
        weaponMaxMP += item.upgradeAmount;
        playerWeapon.SetAdditionalWeaponMaxMP(weaponMaxMP);
        playerWeapon.upgradeLevel++;
        break;
    }
    }
}