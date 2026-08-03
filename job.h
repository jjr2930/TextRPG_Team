#pragma once

#include <string>
#include <vector>

#include "skill.h"

class Job {
private:
    std::string name;
    enum class JobType{Warrior = 1,Mage = 2,Thief = 3,Archer = 4};
    
protected:
    explicit Job(const std::string& name);

public:
    virtual ~Job() = default;

    const std::string& GetName() const;

    virtual const std::vector<Skill>&
        GetSkills() const = 0;

    static const Job* SelectJob();
};

class Warrior : public Job {
public:
    Warrior();

    const std::vector<Skill>&
        GetSkills() const override;
};

class Mage : public Job {
public:
    Mage();

    const std::vector<Skill>&
        GetSkills() const override;
};

class Thief : public Job {
public:
    Thief();

    const std::vector<Skill>&
        GetSkills() const override;
};

class Archer : public Job {
public:
    Archer();

    const std::vector<Skill>&
        GetSkills() const override;
};