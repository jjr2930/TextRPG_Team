#pragma once

class Battle {
public:
	virtual float Attack() = 0;
	virtual void TakeDamage(float damage) = 0;
};