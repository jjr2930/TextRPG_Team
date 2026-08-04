#pragma once
#include "Monster.h"

class Slime : public Monster{
public:
	// 슬라임 생성자 Item정보와 플레이어의 레벨이 필요
	Slime(ItemDatabase* itemDB ,int level);	

	virtual void Attack() override;	//공격 메서드
	virtual void TakeDamage(int damage) override;	// 피격 메서드

	void NomalAttack();		// 슬라임 기본 공격 power 그대로 공격
	void ComboAttack();		// 슬라임 연속 공격 power/2로 공격
	void PowerfulAttack();		// 슬라임 강한 공격 power*2로 공격
};

