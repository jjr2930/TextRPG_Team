#include <iostream>
#include <string>

#include "Inventory.h"
#include "ItemDatabases.h"


const std::vector<Inventory::InventoryItem>& Inventory::GetItems() const
{
    return items;
}

bool Inventory::AddItem(int itemIdentifier, int quantity) {
    if (quantity == 0) {
        return false;
    }

    for (auto item = items.begin(); item != items.end(); ++item) {
        if (item->itemIdentifier != itemIdentifier) {
            continue;
        }

        int newQuantity = item->quantity + quantity;

        if (newQuantity < 0) {
            return false;
        } //보유 수량보다 많이 사용/판매하는 경우

        if (newQuantity == 0) {
            items.erase(item);
            return true;
        } //수량이 0이면 인벤토리에서 제거

        item->quantity = newQuantity;
        return true;
    }

    if (quantity < 0) {
        return false;
    } // 보유하지 않은 아이템이 음수로 추가되는것 방지

    items.push_back({itemIdentifier, quantity});
    //새로운 아이템인경우
    return true;
}

void Inventory::ShowItems() const {
    std::cout << "소지품:\n";

    if (items.empty()) {
        std::cout << "없음\n";
        return;
    }

    ItemDatabase itemDatabase;

    for (const InventoryItem& inventoryItem : items) {
        const auto found =
            itemDatabase.allItems.find(
                inventoryItem.itemIdentifier
            );

        if (found != itemDatabase.allItems.end()) {
            const Item& item = found->second;

            std::cout
                << item.name
                << " x"
                << inventoryItem.quantity
                << '\n';
        }
        else {
            std::cout
                << "알 수 없는 아이템(ID: "
                << inventoryItem.itemIdentifier
                << ") x"
                << inventoryItem.quantity
                << '\n';
        }
    }
}
