#pragma once

class Battle {
public:
    virtual void DoMyTurn();
	virtual void Attack() = 0 ;
	virtual void TakeDamage(int damage) = 0;

protected:
    Battle* target;
};