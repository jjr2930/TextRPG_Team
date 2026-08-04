#pragma once
#include <vector>
#include <cstddef>

#include "Item.h"

class Character;

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
    void OpenItemMenu(Character& character);

    bool UsePotionAt(
        std::size_t index,
        Character& character
    );
private:
    bool UseItemAt(
        std::size_t index,
        Character& character
    );
};

