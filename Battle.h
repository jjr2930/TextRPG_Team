#pragma once

class Battle {
protected:
	Battle* target;
public:
	Battle();
	void SetTarget(Battle* target);

    virtual void DoMyTurn();
	virtual void Attack() = 0 ;
	virtual void TakeDamage(int damage) = 0;
};