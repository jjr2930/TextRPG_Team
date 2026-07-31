#include <iostream>
#include <string>
#include <format>
#include <conio.h>

#include "Shop.h"
#include "Character.h"
#include "ItemDatabases.h"
#include "UtilityMethods.h"

using namespace std;

Shop::Shop(ItemDatabase* itemDatabase, Character* character)
    : itemDatabase(*itemDatabase)
    , character(*character)
{
}

void Shop::PrintMainMenu() {
    while (true) {
        system("cls");
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
                UtilityMethods::WaitForKey();
                break;
        }
    }
}

void Shop::PrintSellMenu()
{
    while (true) {
        system("cls");
        const auto& inventoryItems = character.GetInventory().GetItems();
        size_t inventorySize = inventoryItems.size();
        if (inventorySize == 0) {
            cout << "판매할 아이템이 없습니다." << endl;
            UtilityMethods::WaitForKey();
            return;
        }

        cout << "판매할 아이템을 선택하세요." << endl;
        cout << format("1 ~ {}: 판매할 아이템", inventorySize) << endl;
        cout << "0: 종료" << endl;
        cout << "----------------------------------------" << endl;

        for (size_t i = 0; i < inventorySize; ++i) {
            const auto& item = inventoryItems[i];
            const auto& itemInfo = itemDatabase.GetItem(item.itemIdentifier);
            cout << format("{}: {} (수량: {})", i + 1, itemInfo.name, item.quantity) << endl;
        }

        //for llop display player inventory
        int input;
        cin >> input;

        if (1 <= input && input <= inventorySize) {
            int index = input - 1;
            const auto& item = inventoryItems[index];
            const auto& itemInfo = itemDatabase.GetItem(item.itemIdentifier);
            float itemValue = static_cast<float>(itemInfo.value);
            float sellPrice = itemValue * 0.6f; // 판매 가격은 아이템 가격의 60%
            
            string itemName = itemInfo.name;
            character.GetInventory().SetItemQuantity(item.itemIdentifier, item.quantity - 1); // 판매 후 수량 감소
            character.SetMoney(character.GetMoney() + static_cast<int>(sellPrice)); // 골드 증가
            cout << format("판매한 아이템: {} 판매 가격: {} 현재 골드: {}", itemName, sellPrice, character.GetMoney()) << endl;
            UtilityMethods::WaitForKey();
        }
        else if (input == 0) {
            break;
        }
        else {
            cout << "잘못된 입력입니다. 다시 시도해주세요." << endl;
            UtilityMethods::WaitForKey();
        }
    }
}

void Shop::PrintBuyMenu() {
    while (true) {        
        system("cls");
        size_t itemSize = itemDatabase.allItems.size();
        cout << "구매할 아이템을 선택하세요." << endl;
        cout << format("1 ~ {}: 구매할 아이템", itemSize) << endl;
        cout << "0: 종료" << endl;
        cout << "----------------------------------------" << endl;
        int count = 1;
        for (auto iter = itemDatabase.allItems.begin(); 
            iter != itemDatabase.allItems.end(); ++iter) {
            cout << format("{}: {} (가격: {})", count, iter->second.name, iter->second.value) << endl;
            ++count;
        }
        //for loop display shop inventory
        int input;
        cout << ">> ";
        cin >> input;

        if (1 <= input && input <= itemSize) {
            int index = input - 1;
            auto iter = itemDatabase.allItems.begin();
            std::advance(iter, index);

            int currentMoney = character.GetMoney();
            if (currentMoney >= iter->second.value) {
                currentMoney -= iter->second.value;
                character.SetMoney(currentMoney);
                character.GetInventory().AddItem(iter->first, 1);
                cout << format("구매한 아이템: {} 현재 골드: {}", iter->second.name, currentMoney) << endl;
            }
            else {
                cout << format("골드가 부족합니다. 현재 골드: {}", currentMoney) << endl;
            }

            UtilityMethods::WaitForKey();
        }
        else if (input == 0) {
            break;
        }
        else {
            cout << "잘못된 입력입니다. 다시 시도해주세요." << endl;
            UtilityMethods::WaitForKey();
        }
    }
}
