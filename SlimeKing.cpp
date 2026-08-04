#include <iostream>
#include <string>
#include "SlimeKing.h"
#include "Character.h"

SlimeKing::SlimeKing(ItemDatabase* itemDB, int level)
	:Monster(" 제일 거대한 슬라임 ", 150, 250, 8, 12, 100, itemDB, 30, level) {};

SlimeKing::~SlimeKing() {}

Item SlimeKing::GetItem() {
	int randomNum = random.GetRandomValue(109, 111);
	return itemDB->GetItem(randomNum);
}

void SlimeKing::Attack() {

	int currentPower = power;
	int damageCount = 1;

	if (currentHp <= (maxHp / 2)) {

		damageCount = 3;
		currentPower = (power * 2) / 3;

		std::cout << " 슬라임 점액을 뱉으려고 기를 모읍니다.\n" << std::endl;
		std::cout << " 크루루룽~~ 퉷!퉷!!퉷!!! " << currentPower  << " x 3" << "\n" << std::endl;
		std::cin.get();
	}
	else {

		std::cout << " 몸에서 길쭉하게 늘어난 슬라임 점액을 휘두릅니다. " << "(" << currentPower << ")" << "\n" << std::endl;
		std::cin.get();
	}

	// 위에 선언해놓은 카운트를 사용해 데미지 횟수 설정
	// 정의해놓은 랜덤함수로 데미지 살짝 변동 추가
	for (int i = 1; i <= damageCount; i++) {

		int swing = random.GetRandomValue(-1, 1);
		currentPower = currentPower + swing;
		// if (currentPower < 1) currentPower = 1;
	}

	Monster::target->TakeDamage(power);
}

void SlimeKing::TakeDamage(int damage) {
	currentHp -= damage;

	if (currentHp <= (maxHp / 2) && !isRage) {
		isRage = true;

		std::cout << "===================================================\n" << std::endl;
		std::cout << " 푸루루루루루룽!!!!!!! 프루프루프룽~~~~~\n" << std::endl;
		std::cout << " [분노 모드]: 공격력이 강화되고 3연속 공격으로 바뀝니다.\n" << std::endl;
		std::cout << "===================================================\n" << std::endl;
		std::cin.get();
	}

	if (currentHp < 0) {
		std::cout << "===================================================\n" << std::endl;
		std::cout << " 푸루루룽~~~~푸루...룽......\n" << std::endl;
		std::cout << "===================================================\n" << std::endl;
		std::cin.get();

		Item droppedItem = this->GetItem();
		std::cout << "===================================================\n" << std::endl;
		std::cout << " 제일 거대한 슬라임이 쓰러졌다!\n" << std::endl;
		std::cout << " [획득 아이템]: " << droppedItem.name << std::endl;
		std::cout << "===================================================\n" << std::endl;
		std::cin.get();
	}
}

