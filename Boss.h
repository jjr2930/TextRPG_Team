#pragma once
#ifndef _H_
#define _H_

#include "Monster.h"

class Boss : public Monster
{
public:
	Boss(Character* Character);

	~Boss();

	void attack(Character* Character);
};

#endif
