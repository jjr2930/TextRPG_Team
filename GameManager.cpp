#include "GameManager.h"


GameManager::GameManager() {

};

void GameManager::battle() {
	Monster monster(); // battle 실행 시 몬스터 생성, 배틀 종료시 제거
	while (!isCharacterDead(0) || !isMonsterDead(0)) {
	}
};

void GameManager::encounter() {
	battle(); // 조우 시 배틀 호출
};

bool GameManager::isCharacterDead(int hp) {
	if (hp <= 0) {
		gameover();
		return true;
	}
	return false
};

bool GameManager::isMonsterDead(int hp) {
	if (hp <= 0) {
		std::cout << "승리!" << std::endl;
		return true;
	}
	return false;
};

void GameManager::shopEnter() {

};

bool GameManager::gameover() {

};