#pragma once
#include <vector>

class Inventory {
private:
    struct InventoryItem {
        int mItemIdentifier;
        int mQuantity;
    };

    std::vector<InventoryItem> mItems;

public:
    void AddItem(int itemIdentifier, int quantity);
    void ShowItems() const;
};
