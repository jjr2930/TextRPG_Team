#pragma once
#include "Item.h"
#include <unordered_map>



class ItemDatabase
{
public: 
    ItemDatabase();

    std::unordered_map<int, Item> allItems;
};