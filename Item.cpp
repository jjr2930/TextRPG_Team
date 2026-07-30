#include "Item.h"
#include <iostream>
#include <vector>
#include <string>
#include "Inventory.h"
#include "Character.h"


void Item::usePotion(const Item& item, Character& character){
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

