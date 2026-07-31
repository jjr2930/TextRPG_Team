#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <random>
#include <conio.h>
class Tools {
public:
	static int GetIntegerInRange(int minValue, int maxValue); // 범위 내 정수 입력을 받는 함수, 다른거 들어가면 다시 입력받게 함
	static void WaitForKey(); // 아무 키나 누르면 진행되는 함수
};