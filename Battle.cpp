#include "Battle.h"

Battle::Battle() : target(nullptr) {};

void Battle::SetTarget(Battle* target) {
    this->target = target;
}

void Battle::DoMyTurn()
{
    Attack();
}
