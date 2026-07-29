#pragma once
#include "Item.h"
#include <vector>

class ItemDatabase
{
public: 
    ItemDatabase();

    std::vector<Item> loadedItems;
};