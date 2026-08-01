#pragma once

#include "DungeonEvent.h"

class GreenSlimeForestEvent : public DungeonEvent {
public:
	GreenSlimeForestEvent()
		: DungeonEvent({
			{
				DungeonEventType::Exploration,
				"통통 튀는 길잡이",
				"작은 슬라임 한 마리가 앞을 가로막고 통통 뛰기 시작한다.\n"
				"뒤를 따라가자 끈적한 늪을 피해 갈 수 있는 안전한 오솔길이 나타났다."
			},
			{
				DungeonEventType::Treasure,
				"점액에 잠긴 보급품",
				"나무뿌리 아래에서 녹슨 모험가 가방을 발견했다.\n"
				"초록색 점액을 걷어 내자 아직 쓸 만한 물자들이 모습을 드러냈다."
			},
			{
				DungeonEventType::Trap,
				"위장한 슬라임 늪",
				"평범한 웅덩이처럼 보였던 바닥이 갑자기 발목을 휘감는다.\n"
				"늪처럼 뭉친 슬라임들이 사방에서 몸을 부풀리고 있다."
			},
			{
				DungeonEventType::Rest,
				"은은하게 빛나는 샘",
				"달빛을 머금은 작은 샘 주변에는 슬라임들도 얌전히 쉬고 있다.\n"
				"맑은 물로 몸을 씻자 지친 몸과 끈적한 장비가 한결 가벼워졌다."
			},
			{
				DungeonEventType::Exploration,
				"슬라임들의 합창",
				"수풀 너머에서 여러 슬라임이 박자를 맞춰 튀어 오르고 있다.\n"
				"그 소리에 섞여 숲 깊은 곳에서 울리는 거대한 진동이 느껴진다."
			}
		}) {}
};
