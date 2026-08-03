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

    void SetItemQuantity(int itemID, int quantity);
};
