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

    bool AddItem(int itemIdentifier, int quantity);
    void ShowItems() const;
};
