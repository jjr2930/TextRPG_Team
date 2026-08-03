#include <iostream>

#include "skill.h"
#include "Character.h"
#include "Battle.h"

Skill::Skill(
    const std::string& name,
    int requiredLevel,
    int activationChance,
    int manaCost,
    int damagePercent
)
    : name(name),
      requiredLevel(requiredLevel),
      activationChance(activationChance),
      manaCost(manaCost),
      damagePercent(damagePercent)
{
}

const std::string& Skill::GetName() const
{
    return name;
}

int Skill::GetRequiredLevel() const
{
    return requiredLevel;
}

int Skill::GetActivationChance() const
{
    return activationChance;
}

int Skill::GetManaCost() const
{
    return manaCost;
}

int Skill::GetDamagePercent() const
{
    return damagePercent;
}

bool Skill::CanUse(const Character& character) const
{
    return character.GetCurrentMP() >= manaCost;
}

void Skill::Use(
    Character& character,
    Battle& target
) const {
    if (!CanUse(character)) {
        return;
    }

    character.SetCurrentMP(
        character.GetCurrentMP() - manaCost
    );

    const int damage =
        character.GetAttack() * damagePercent / 100;

    std::cout
        << character.GetName()
        << "이(가) ["
        << name
        << "] 스킬을 사용했습니다!\n";

    target.TakeDamage(damage);
}