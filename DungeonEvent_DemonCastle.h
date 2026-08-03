#pragma once

#include "DungeonEvent.h"

class DemonCastleEvent : public DungeonEvent {
public:
	DemonCastleEvent()
		: DungeonEvent({
			{
				DungeonEventType::Exploration,
				"살아 있는 초상화",
				"복도를 가득 채운 마족들의 초상화가 일제히 시선을 돌린다.\n"
				"그중 찢어진 초상화 뒤에서 비밀 통로로 이어지는 바람이 새어 나온다."
			},
			{
				DungeonEventType::Treasure,
				"저주받은 무기고",
				"검은 사슬로 봉인된 무기고 안에 마력이 깃든 장비들이 놓여 있다.\n"
				"봉인을 건드리자 무기들이 공중에 떠오르며 침입자를 시험한다."
			},
			{
				DungeonEventType::Trap,
				"악마의 눈동자",
				"천장에 새겨진 거대한 눈이 번쩍 뜨이며 붉은 빛을 내뿜는다.\n"
				"경보음과 함께 복도의 벽들이 서서히 안쪽으로 좁혀 오기 시작한다."
			},
			{
				DungeonEventType::Rest,
				"해방을 기다리는 영혼",
				"수정 감옥 속에 갇힌 희미한 영혼이 도움을 청한다.\n"
				"마력 사슬을 끊어 주자 영혼은 마지막 힘으로 따뜻한 축복을 남겼다."
			},
			{
				DungeonEventType::Exploration,
				"뒤집히는 계단",
				"성채의 종이 울리자 계단과 벽이 거대한 톱니바퀴처럼 움직인다.\n"
				"발아래 계단이 뒤집히며 마왕의 방과는 다른 깊은 지하로 길이 이어진다."
			}
		}) {}
};
