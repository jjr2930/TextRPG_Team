#include "Item.h"
#include <iostream>
#include <vector>
#include <string>
#include "Inventory.h"
#include "Character.h"


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
    /*case ItemEffect::RestoreStamina: {
        int currentStamina = character.GetCurrentStamina();
        currentStamina += item.effectAmount;
        character.SetCurrentStamina(currentStamina);
        break;
    }*/
    case ItemEffect::RestoreMana: {
        int currentMana = character.GetCurrentMP();
        currentMana += item.effectAmount;
        character.SetCurrentMP(currentMana);
        break;
    }
    }
}

//승용: 제가 생각했던 구조는 이런거라 아예 함수를 UseItem 하나로 묶고 그 안에서 if 로 아이템 타입을 받아서
// 무기면 착용이 되고 포션이면 사용이 되는 그런 형태면 더 낫지 않을까요
void Item::UseWeapon(
    const Item& item,
    Character& character
) {
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

/*
void Item::UseWeapon(const Item& item, Character& character) {
    switch (item.itemWeapon)
    {
    case ItemWeapon::Staff: {
        int currentAttack = character.GetAdditionalAttack();
        int currentDefense = character.GetAdditionalDefense();
        int maxMP = character.GetAdditionalMaxMP();
        currentAttack += item.weaponAttack;
        currentDefense += item.weaponDefense;
        maxMP += item.weaponMaxMP;
        character.SetAdditionalAttack(currentAttack);
        character.SetAdditionalDefense(currentDefense);
        character.SetAdditionalMaxMP(maxMP);
        break;
    }
    case ItemWeapon::SwordnShield: {
        int currentAttack = character.GetAdditionalAttack();
        int currentDefense = character.GetAdditionalDefense();
        int maxHP = character.GetAdditionalMaxHP();
        currentAttack += item.weaponAttack;
        currentDefense += item.weaponDefense;
        maxHP += item.weaponMaxHP;
        character.SetAdditionalAttack(currentAttack);
        character.SetAdditionalDefense(currentDefense);
        character.SetAdditionalMaxHP(maxHP);
        break;
    }
    case ItemWeapon::TwoHand: {
        int currentAttack = character.GetAdditionalAttack();
        int currentDefense = character.GetAdditionalDefense();
        int maxHP = character.GetAdditionalMaxHP();
        currentAttack += item.weaponAttack;
        currentDefense += item.weaponDefense;
        maxHP += item.weaponMaxHP;
        character.SetAdditionalAttack(currentAttack);
        character.SetAdditionalDefense(currentDefense);
        character.SetAdditionalMaxHP(maxHP);
        break;
    }
    case ItemWeapon::Bow: {
        int currentAttack = character.GetAdditionalAttack();
        int currentDefense = character.GetAdditionalDefense();
        currentAttack += item.weaponAttack;
        currentDefense += item.weaponDefense;
        character.SetAdditionalAttack(currentAttack);
        character.SetAdditionalDefense(currentDefense);
        break;
    }
    }
}
*/