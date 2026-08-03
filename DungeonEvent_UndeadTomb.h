#pragma once

#include "DungeonEvent.h"

class UndeadTombEvent : public DungeonEvent {
public:
	UndeadTombEvent()
		: DungeonEvent({
			{
				DungeonEventType::Exploration,
				"길을 밝히는 혼불",
				"푸른 혼불 하나가 어두운 복도 끝에서 천천히 손짓한다.\n"
				"혼불을 따라가자 무너진 통로 뒤에 감춰진 오래된 묘실이 나타났다."
			},
			{
				DungeonEventType::Treasure,
				"수호 기사의 유품",
				"녹슨 갑옷을 입은 해골이 작은 상자를 품에 안고 잠들어 있다.\n"
				"상자 안에는 망자를 위해 바친 금화와 온전한 보급품이 남아 있다."
			},
			{
				DungeonEventType::Trap,
				"뼈 화살 함정",
				"낡은 석판을 밟는 순간 벽 안쪽에서 기계음이 울린다.\n"
				"뾰족하게 다듬어진 뼈 화살들이 어둠 속에서 쏟아져 나온다."
			},
			{
				DungeonEventType::Rest,
				"망자의 추모실",
				"꺼지지 않는 촛불과 이름 없는 비석들이 놓인 조용한 방을 발견했다.\n"
				"잠시 묵념하자 차가운 기운이 걷히고 마음이 차분해졌다."
			},
			{
				DungeonEventType::Exploration,
				"흔들리는 봉인 석관",
				"붉은 봉인문자가 새겨진 거대한 석관이 거칠게 흔들린다.\n"
				"관 안쪽에서 무언가 손톱으로 돌을 긁는 소리가 끊임없이 들려온다."
			}
		}) {}
};
