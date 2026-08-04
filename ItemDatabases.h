#pragma once
#include "Item.h"
#include <unordered_map>



class ItemDatabase
{
public: 
    ItemDatabase();
    
    const Item& GetItem(int itemID);

    std::unordered_map<int, Item> allItems;
};