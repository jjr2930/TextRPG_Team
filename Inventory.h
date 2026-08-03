#pragma once
#include <vector>

class Inventory {
private:
    struct InventoryItem {
        int itemIdentifier;
        int quantity;
    };

    std::vector<InventoryItem> items;

public:
    const std::vector<InventoryItem>& GetItems() const;
    bool AddItem(int itemIdentifier, int quantity);
    void ShowItems() const;
    void SetItemQuantity(int itemIdentifier, int quantity) {
        size_t size = items.size();
        for (size_t i = 0; i < size; ++i) {
            if (items[i].itemIdentifier == itemIdentifier) {
                items[i].quantity = quantity;
                if (items[i].quantity <= 0) {
                    items.erase(items.begin() + i);
                }
                return;
            }
        }
    }
};
