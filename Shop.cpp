#include "Shop.h"
#include <iostream>

using namespace std;

Shop::Shop()
    : itemsForSale({ "체력 포션", "파워 업 포션" })
{
}

void Shop::PrintMainMenu() {
    while (true) {
        cout << "상점에 오신것을 환영합니다." << endl;;
        cout << "1. 판매" << endl;
        cout << "2. 구매" << endl;
        cout << "3. 종료" << endl;

        SelectedMenuType choice;
        int input;
        cin >> input;
        choice = static_cast<SelectedMenuType>(input);
        switch (choice) {
            case SelectedMenuType::Sell:
                PrintSellMenu();
                break;
            
            case SelectedMenuType::Buy:
                PrintBuyMenu();
                break;

            case SelectedMenuType::Exit:
                return;

            default:
                cout << "잘못된 입력입니다. 다시 시도해주세요." << endl;
                break;
        }
    }
}

void Shop::PrintSellMenu()
{
    while (true) {
        cout << "판매할 아이템을 선택하세요." << endl;
        cout << "1 ~ 9: 판매할 아이템" << endl;
        cout << "0: 종료" << endl;

        //for llop display player inventory
        int input;
        cin >> input;

        if (MIN_ITEM_NUMBER_FOR_SALE <= input && input <= MAX_ITEM_NUMBER_FOR_SALE) {
            //checking out of range;
            //1. remove item from player inventory
            //2. add gold to player inventory
        }
        else if (input == 0) {
            break;
        }
        else {
            cout << "Invalid input, please try again." << endl;
        }
    }
}

void Shop::PrintBuyMenu() {
    while (true) {
        cout << "구매할 아이템을 선택하세요." << endl;
        cout << "1 ~ 9: 구매할 아이템" << endl;
        cout << "0: 종료" << endl;

        //for loop display shop inventory
        int input;
        cin >> input;

        if (MIN_ITEM_NUMBER_FOR_BUY <= input && input <= MAX_ITEM_NUMBER_FOR_BUY) {
            //checking out of range;
            //1. remove gold from player inventory
            //2. add item to player inventory
        }
        else if (input == 0) {
            break;
        }
        else {
            cout << "잘못된 입력입니다. 다시 시도해주세요." << endl;
        }
    }
}
