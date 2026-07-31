#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <random>
#include <conio.h>

int GetIntegerInRange(int minValue, int maxValue); // 범위 내 정수 입력을 받는 함수, 다른거 들어가면 다시 입력받게 함
int GetRandomValue(int minValue, int maxValue); // 랜덤 정수 내뱉는 함수
void WaitForKey(); // 아무 키나 누르면 진행되는 함수
