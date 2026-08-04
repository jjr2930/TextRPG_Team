#include <iostream>
#include <string>
#include "SkeletonKing.h"
#include "Character.h"

SkeletonKing::SkeletonKing(ItemDatabase* itemDB, int level)
	:Monster("망자들에 묘지기", 80, 100, 15, 20, 70, itemDB, 50, level) {};

SkeletonKing::~SkeletonKing() {}

Item SkeletonKing::GetItem() {
	int randomNum = random.GetRandomValue(112, 114);
	return itemDB->GetItem(randomNum);
}

void SkeletonKing::Attack() {
	
	int currentPower = power;

	if (!isReborn && currentHp <= 1) {

		isReborn = true;
		currentHp = maxHp;
		power = power * 2;
		currentPower = power;
		name = "진정한 죽은자들에 왕";

		std::cout << " 자기 몸에 있는 해골들에 뼛조각을 던졌다!\n" << std::endl;
		std::cin.get();
	}
	else {

		std::cout << " 손에 있는 뼈다귀를 휘두릅니다.\n" << std::endl;
		std::cin.get();
	}

	Monster::target->TakeDamage(power);
}

void SkeletonKing::TakeDamage(int damage) {
	currentHp -= damage;

	if (!isReborn && currentHp <= 0) {
		currentHp = 1;
		std::cout << "===================================================\n" << std::endl;
		std::cout << " 크하하하!!! 역시 여기까지 도달한 자인가...\n" << std::endl;
		std::cout << " 허나 너의 여정은 여기서 끝이다~ 내 본 모습을 보여주지!!\n" << std::endl;
		std::cout << " 내 아이들이 이리오거라!!!\n" << std::endl;
		std::cout << " [ 주변에 해골들과 뼈들이 묘지기 스켈레톤으로 흡수되기 시작한다. ]\n" << std::endl;
		std::cout << " 너의 시체도 여기에 묻어주마!!!!!!!!\n" << std::endl;
		std::cout << "===================================================\n" << std::endl;
		std::cin.get();
	}

	else if (currentHp <= 0) {
		currentHp = 0;

		std::cout << "===================================================\n" << std::endl;
		std::cout << " 크아아아아아아아아악~~~~ 나의 힘이!!!! 나의 권력이!!!!!!~~~~\n" << std::endl;
		std::cout << " 두고보자!! 인간녀석!!!!!!!!!!!~~~~\n" << std::endl;
		std::cout << "===================================================\n" << std::endl;
		std::cin.get();

		Item droppedItem = this->GetItem();
		std::cout << "===================================================\n" << std::endl;
		std::cout << " 진정한 죽은자들에 왕이 쓰러졌다!\n" << std::endl;
		std::cout << " [획득 아이템]: " << droppedItem.name << std::endl;
		std::cout << "===================================================\n" << std::endl;
		std::cin.get();
	}
}