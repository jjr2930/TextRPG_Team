#include <iostream>
#include <string>

#include "Inventory.h"
#include "Character.h"
#include "Tools.h"


const std::vector<Inventory::InventoryItem>& Inventory::GetItems() const
{
    return items;
}

bool Inventory::AddItem(const Item& item, int quantity) {
    if (quantity == 0) {
        return false;
    }

    if (item.itemType == ItemType::Weapon) {
    if (quantity < 0) {
        return false;
    }

    for (int i = 0; i < quantity; ++i) {
        items.push_back({item, 1});
    }

    return true;
    }

    for (auto itemi = items.begin(); itemi != items.end(); ++itemi) {
        if (itemi->item.itemID != item.itemID) {
            continue;
        }

        const int newQuantity = itemi->quantity + quantity;

        if (newQuantity < 0) {
            return false;
        } //보유 수량보다 많이 사용/판매하는 경우

        if (newQuantity == 0) {
            items.erase(itemi);
            return true;
        } //수량이 0이면 인벤토리에서 제거

        itemi->quantity = newQuantity;
        return true;
    }

    if (quantity < 0) {
        return false;
    } // 보유하지 않은 아이템이 음수로 추가되는것 방지

    items.push_back({item, quantity});
    //새로운 아이템인경우
    return true;
}

void Inventory::ShowItems() const {
    std::cout << "소지품:\n";

    if (items.empty()) {
        std::cout << "없음\n";
        return;
    }

    for (const InventoryItem& inventoryItem : items) {
        std::cout
            << inventoryItem.item.name
            << " x"
            << inventoryItem.quantity
            << '\n';
    }
}


void Inventory::SetItemQuantity(int itemID,int quantity) {
    for (std::size_t i = 0; i < items.size(); ++i) {
        if (items[i].item.itemID != itemID) {
            continue;
        }
        if (quantity <= 0) {
            items.erase(items.begin() + i);
        }
        else {
            items[i].quantity = quantity;
        }
        return;
    }
}

bool Inventory::UsePotionAt(
    std::size_t index,
    Character& character
) {
    if (index >= items.size()) {
        return false;
    }

    InventoryItem& inventoryItem = items[index];

    if (inventoryItem.quantity <= 0) {
        return false;
    }

    if (inventoryItem.item.itemType != ItemType::Potion) {
        return false;
    }

    const std::string potionName =
        inventoryItem.item.name;

    inventoryItem.item.UsePotion(
        inventoryItem.item,
        character
    );

    --inventoryItem.quantity;

    if (inventoryItem.quantity == 0) {
        items.erase(items.begin() + index);
    }

    std::cout
        << character.GetName()
        << "이(가) "
        << potionName
        << "을 사용했습니다.\n";

    return true;
}

void Inventory::OpenItemMenu(
    Character& character
) {
    while (true) {
        system("cls");

        std::cout << "========== 소지품 ==========\n";

        if (items.empty()) {
            std::cout << "보유한 아이템이 없습니다.\n";
            std::cout << "\n0. 돌아가기\n";
            std::cout << ">> ";

            Tools::GetIntegerInRange(0, 0);
            return;
        }

        for (std::size_t i = 0; i < items.size(); ++i) {
            const InventoryItem& inventoryItem =
                items[i];

            const Item& item =
                inventoryItem.item;

            std::cout
                << i + 1
                << ". "
                << item.name
                << " x"
                << inventoryItem.quantity;

            switch (item.itemType)
            {
            case ItemType::Weapon:
                std::cout << " [무기]";

                if (character.GetCurrentEquippedWeapon()
                    == item.itemID) {
                    std::cout << " [장착 중]";
                }
                break;

            case ItemType::Potion:
                std::cout << " [물약]";
                break;

            case ItemType::Miscellaneous:
                std::cout << " [기타]";
                break;
            }

            std::cout << '\n';
        }

        std::cout << "\n";
        std::cout << "사용하거나 장착할 아이템의 번호를 선택하세요.\n";
        std::cout << "0. 돌아가기\n";
        std::cout << ">> ";

        const int selection =
            Tools::GetIntegerInRange(
                0,
                static_cast<int>(items.size())
            );

        if (selection == 0) {
            return;
        }

        const std::size_t selectedIndex =
            static_cast<std::size_t>(selection - 1);

        UseItemAt(selectedIndex, character);

        Tools::WaitForKey();
    }
}

bool Inventory::UseItemAt(
    std::size_t index,
    Character& character
) {
    if (index >= items.size()) {
        return false;
    }

    InventoryItem& inventoryItem = items[index];
    Item& item = inventoryItem.item;

    if (inventoryItem.quantity <= 0) {
        return false;
    }

    switch (item.itemType)
    {
    case ItemType::Potion:
    {
        std::cout
            << item.name
            << "을 사용했습니다.\n";

        item.UsePotion(item, character);

        --inventoryItem.quantity;

        if (inventoryItem.quantity == 0) {
            items.erase(items.begin() + index);
        }

        

        return true;
    }

    case ItemType::Weapon:
        item.UseWeapon(item, character);

        std::cout
            << item.name
            << "을 장착했습니다.\n";

        // 장착해도 인벤토리에서 제거하지 않음
        return true;

    case ItemType::Miscellaneous:
        std::cout
            << "사용할 수 없는 아이템입니다.\n";
        return false;
    }

    return false;
}