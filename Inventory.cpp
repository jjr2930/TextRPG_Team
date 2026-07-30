#include <iostream>
#include <string>

#include "Inventory.h"
#include "ItemDatabases.h"


void Inventory::AddItem(int itemIdentifier, int quantity) {
    if (quantity <= 0)
        return;

    for (InventoryItem& item : mItems) {
        if (item.mItemIdentifier == itemIdentifier) {
            item.mQuantity += quantity;
            return;
        }
    }

    mItems.push_back({itemIdentifier, quantity});
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
