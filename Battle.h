#pragma once

class Battle {
public:
	virtual void Attack(Battle* other) = 0 ;
	virtual void TakeDamage(int damage) = 0;
	virtual void DoMyTurn(Battle* other);

protected:
    Battle* target = nullptr;
};
