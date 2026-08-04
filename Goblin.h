#pragma once
#include "Monster.h"

class Goblin : public Monster{
public:
	// 고블린 생성자 item 정보와 플레이어의 레벨이 필요
	Goblin(ItemDatabase* itemDB, int level);

	virtual void Attack() override;	// 공격 메서드
	virtual void TakeDamage(int damage) override;	// 피격 메서드

	virtual Item GetItem() override;

	void NomalAttack();	// 고블린 기본 공격 power 그대로 공격
	void ComboAttack();	// 고블린 연속 공격 power/3로 공격
};

