#pragma once

#include <string>

class Character;
class Battle;

class Skill {
private:
    std::string name;

    int requiredLevel;
    int activationChance;
    int manaCost;
    int damagePercent;

public:
    Skill(
        const std::string& name,
        int requiredLevel,
        int activationChance,
        int manaCost,
        int damagePercent
    );

    const std::string& GetName() const;

    int GetRequiredLevel() const;
    int GetActivationChance() const;
    int GetManaCost() const;
    int GetDamagePercent() const;

    bool CanUse(const Character& character) const;

    void Use(
        Character& character,
        Battle& target
    ) const;
};