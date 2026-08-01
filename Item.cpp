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

void Item::WieldWeapon(const Item& item, Character& character) {
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
    void Item::UpgradeWeapon(const Item & item, Character & character) {
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

}