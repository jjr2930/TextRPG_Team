#pragma once
#include <string>


#include "Battle.h"
#include "Item.h"
#include "ItemDatabases.h"
#include "Random.h"

class Item;

class Monster : public Battle {
protected:
	Random random;	// 랜덤 클래스
	ItemDatabase* itemDB;
	std::string name;	// 이름
	int maxHp;				//최대 체력
	int currentHp;			// 현재 체력
	int power;				// 공격력
	int dropExp;			// 드랍 경험치
	Item* item;			// 아이템
	int gold;					// 드랍하는 골드

public:
	// 몬스터 생성자
	Monster(std::string name, int minHp, int maxHp, int minPower, int maxPower, int dropExp, ItemDatabase* itemDB, int price, int level);
	int GetCurrentHp();
	int GetPower();
	int GetDropExp();
	std::string GetName();
	virtual Item GetItem();
	int RandomGold();

	virtual void SetHp(int hp);
	virtual void SetPower(int power);

	virtual int RandomHp(int min, int max, int level);
	virtual int RandomPower(int min, int max, int level);

	virtual ~Monster() = default;
};