#include <iostream>
#include <Windows.h>

#include "GameManager.h"

int main(int argc, char *argv[])
{
    // 콘솔 출력 인코딩을 UTF-8로 설정
    SetConsoleOutputCP(CP_UTF8);

    // 콘솔에서 한글 입력도 받을 경우 필요
    SetConsoleCP(CP_UTF8);


    GameManager gameManager;
    while (true) {
        gameManager.encounter();
        gameManager.showMainMenu();
    }
    return 0;
}