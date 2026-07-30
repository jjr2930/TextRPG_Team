#include <iostream>
#include <string>

#include "Inventory.h"
#include "ItemDatabases.h"


bool Inventory::AddItem(int itemIdentifier, int quantity) {
    if (quantity == 0) {
        return false;
    }

    for (auto item = mItems.begin(); item != mItems.end(); ++item) {
        if (item->mItemIdentifier != itemIdentifier) {
            continue;
        }

        int newQuantity = item->mQuantity + quantity;

        if (newQuantity < 0) {
            return false;
        } //보유 수량보다 많이 사용/판매하는 경우

        if (newQuantity == 0) {
            mItems.erase(item);
            return true;
        } //수량이 0이면 인벤토리에서 제거

        item->mQuantity = newQuantity;
        return true;
    }

    mItems.push_back({itemIdentifier, quantity});
    //새로운 아이템인경우
    return true;
}

void Inventory::ShowItems() const {
    std::cout << "소지품:\n";

    if (mItems.empty()) {
        std::cout << "없음\n";
        return;
    }

    ItemDatabase itemDatabase;

    for (const InventoryItem& inventoryItem : mItems) {
        const auto found =
            itemDatabase.allItems.find(
                inventoryItem.mItemIdentifier
            );

        if (found != itemDatabase.allItems.end()) {
            const Item& item = found->second;

            std::cout
                << item.name
                << " x"
                << inventoryItem.mQuantity
                << '\n';
        }
        else {
            std::cout
                << "알 수 없는 아이템(ID: "
                << inventoryItem.mItemIdentifier
                << ") x"
                << inventoryItem.mQuantity
                << '\n';
        }
    }
}
