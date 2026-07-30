#include "Slime.h"



Slime::Slime(Item* item, int level) : Monster("Slime", 20, 30, 5, 10, 30, item, 20, level) {};

void Slime::Attack(Battle* other) {
	other->TakeDamage(power);
}
void Slime::TakeDamage(int damage) {
	hp -= damage;
}
