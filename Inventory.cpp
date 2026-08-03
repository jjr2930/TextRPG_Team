#include <iostream>
#include <string>

#include "Inventory.h"


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