#pragma once
#include <vector>
#include "Item.h"

class Inventory {
public:
    struct InventoryItem {
        Item item;
        int quantity;
    };

private:
    std::vector<InventoryItem> items;

public:
    const std::vector<InventoryItem>& GetItems() const;
    bool AddItem(const Item& item, int quantity);
    void ShowItems() const;

    void SetItemQuantity(int itemID, int quantity) {
        size_t size = items.size();
        for (size_t i = 0; i < size; ++i) {
            if (items[i].item.itemID == itemID) {
                items[i].quantity = quantity;
                if (items[i].quantity <= 0) {
                    items.erase(items.begin() + i);
                }
                return;
            }
        }
    }
};
