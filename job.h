#pragma once

#include <string>

class Job {
private:
    std::string name;

protected:
    explicit Job(const std::string& name);

public:
    virtual ~Job() = default;

    const std::string& GetName() const;

    static const Job* SelectJob();
};

class Warrior : public Job {
public:
    Warrior();
};

class Mage : public Job {
public:
    Mage();
};

class Thief : public Job {
public:
    Thief();
};

class Archer : public Job {
public:
    Archer();
};
